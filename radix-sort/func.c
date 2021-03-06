#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "func.h"

int pegaDigito(int numero, int divisor){
    return (numero / divisor) % 10; // (123 / 1) % 10 por exemplo
}

int maximo(int lista[], int n){ // lista e tamanho
    int max = lista[0];
    for (int i = 1; i < n; i++){
        if (lista[i] > max)
            max = lista[i];
    }
    return max;
}

void juntaVetores(int *v, int *inicial, int *final, int n){ // concatena dois vetores
    for (int i = 0; i < n; i++) v[i] = inicial[i];
    for (int i = 0; i < n; i++) v[i + n] = final[i];
}

void negativaLista(int *lista, int n){ // deixa todos elementos negativos
    for(int i = 0; i < n; i++) {
        lista[i] = (-1)*lista[i];
    }
}

void inverteLista(int *lista, int n){ // inverte a ordem da lista
    int invertido[n];
    for(int i = 0; i < n; i++) {
        invertido[i] = lista[(n-i)-1];
    }
    for(int i=0; i<n; i++){
        lista[i] = invertido[i];
    }
}

void zeraLista(int *lista, int n){ // define todos elementos de uma lista como sendo 0
    for(int i=0; i<n; i++){
        lista[i] = 0;
    }
}

void retornaListaFinal(int *lista, int *temp, int n){
    int j=0;
    // remove os zeros desnecessarios e retorna à lista original
    for(int i=0; i<n; i++){
        if(temp[i] < 0){
            lista[j] = temp[i];
            j++;
        }
    }
    for(int i=0; i<n; i++){
        if(temp[i] > 0){
            lista[j] = temp[i];
            j++;
        }
    }
}

void countingSort(int *lista, int n, int divisor, int *aux){
    int digito, c[n], s = 0; // c[n] --> vetor contador || s --> soma de prefixo
    zeraLista(c, n);

    for(int i=0; i < n; i++){
        digito = pegaDigito(lista[i], divisor);
        c[digito]++;
    }

    for(int i=0; i < n; i++){ // soma de prefixo, soma todos os elementos antes de i
        int t = c[i];
        c[i] = s;
        s += t;
    }

    for(int i=0; i < n; i++){ // copiar lista no vetor temporario obedecendo a ordem dos prefixos
        digito = pegaDigito(lista[i], divisor);
        aux[c[digito]] = lista[i];
        c[digito]++;
    }

    for(int i=0; i < n; i++) { // lista original recebe a lista auxiliar ordenada
        lista[i] = aux[i];
    }
}

void radixSort(int *lista, int n){
    int *aux = (int *)calloc(n, sizeof(int)), *temp = (int *)calloc(n*2, sizeof(int)), *negativos = (int *)calloc(n, sizeof(int));
    
    for(int i=0; i<n; i++){ // pega todos elementos negativos da lista original, copia para outra lista pega o abs
        if(lista[i]<0){
            negativos[i] = (-1)*lista[i];
            lista[i] = 0;
        }
    }

    int q = maximo(lista, n), k = maximo(negativos, n), divisor = 1; // pega o maior numero do vetor

    while(q > 0){ // ordena lista dos positivos
        countingSort(lista, n, divisor, aux);
        divisor *= 10; // divisor multiplo de 10 para ir pegando sempre a proxima casa decimal
        q /= 10; // diminui a quantidade de casas do maior numero
    }

    divisor = 1; // seta variaveis novamente
    while(k > 0){ // ordena negativos
        countingSort(negativos, n, divisor, aux);
        divisor *= 10; // dividor multiplo de 10 para ir pegando sempre a proxima casa decimal
        k /= 10; // diminui a quantidade de casas do maior numero
    }

    inverteLista(negativos, n); // deixa a lista decrescente
    negativaLista(negativos, n); // deixa os numeros negativos
    juntaVetores(temp, negativos, lista, n); // junta as duas listas em uma so
    retornaListaFinal(lista, temp, n);

    free(aux); // libera memoria
    free(temp); // libera memoria
    free(negativos); // libera memoria
}

void imprimeLista(int *lista, int n) // Funcao que imprime a lista, para evitar repetição de codigo
{
  printf("[ ");
  for (int i = 0; i < n; i++) // Estrutura de repetição que passa por toda a lista e imprime seus valores
  {
    if(i==(n-1)){
            printf("%d ]\n", lista[i]);
        } else{
            printf("%d, ", lista[i]);
        }  
  }
}

void gerarListaAleatoria(int *lista, int len, int m, int n){
  srand( (unsigned)time(NULL) ); // Gera números semi-aleatórios baseado em algumas coisas do computador
  n++; //aumenta n em 1 devido a como a função rand funciona
  for(int j = (n-m); j > 0; j -= RAND_MAX){
    for(int i=0;i<len;i++)
    {
      lista[i]+=(rand()%j); //gera um número aleatório entre 0 e j, j vezes
      //devido ao limite que um número aleatório pode ser gerado: RAND_MAX = 32767
      //listas muito grandes, como as dos experimentos 3.1 + não podem ser geradas
      //então temos que gerar valores aleatórios diversas vezes para satisfazer isso
    }
  }
    for(int i=0;i<len;i++)
    {
      lista[i]+=m; //adiciona o número m (valor mínimo) na lista para que seu valor nunca seja menor que ele
      //isso foi feito para que possamos gerar números negativos ou com o chão sendo > 0
    }
}

void gerarListaCrescente(int *lista, int len){
  for(int i = 0; i < len; i++) lista[i] = i+1;
}

void gerarListaDecrescente(int *lista, int len){
  for(int i = 0; i <= len; i++) lista[len-i] = i;
}