#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

int pegaDigito(int numero, int divisor){
    return (numero / divisor) % 10;
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

// NAO ALTERA NADA NESSA FUNCAO, O ERRO NAO TA AQUI
void countingSort(int *lista, int n, int divisor, int *aux){
    int base = 10;
    int digito, c[base], s = 0; // t --> soma de prefixo || c[base] --> lista de contagem
    zeraLista(c, n);
    zeraLista(aux, n);

    for(int i=0; i < n; i++){
        digito = pegaDigito(lista[i], divisor);
        c[digito]++;
    }

    for(int i=0; i < base; i++){ // soma de prefixo, soma todos os elementos antes de i
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
    int divisor = 1;
    int q = maximo(lista, n); // pega o maior numero do vetor
    int *aux = (int *)calloc(n, sizeof(int));
    int *negativo = (int *)calloc(n, sizeof(int));

    zeraLista(negativo, n);
    for(int i=0; i<n; i++){ // pega todos elementos negativos da lista original, copia para outra lista pega o abs
        if(lista[i]<0){
            negativo[i] = (-1)*lista[i];
            lista[i] = 0;
        }
    }

    while(q > 0){ // ordena lista dos positivos
        countingSort(lista, n, divisor, aux);
        divisor *= 10; // divisor multiplo de 10 para ir pegando sempre a proxima casa decimal
        q /= 10; // diminui a quantidade de casas do maior numero
    }

    // seta variaveis novamente
    divisor = 1;
    q = maximo(negativo, n); // pega o maior numero do vetor
    int *aux2 = (int *)calloc(n, sizeof(int));
    while(q > 0){ // ordena negativos
        countingSort(negativo, n, divisor, aux2);
        divisor *= 10; // dividor multiplo de 10 para ir pegando sempre a proxima casa decimal
        q /= 10; // diminui a quantidade de casas do maior numero
    }
    inverteLista(negativo, n); // deixa a lista decrescente
    negativaLista(negativo, n); // deixa os numeros negativos

    int *aux3 = (int *)calloc(n*2, sizeof(int));
    juntaVetores(aux3, negativo, lista, n); // junta as duas listas em uma so

    for(int i=0, j=0; i<(n*2); i++){ // remove os zeros e retorna à lista original
        if(aux3[i] != 0){
            lista[j] = aux3[i];
            j++;
        }
    }

    free(aux); // libera memoria
    free(aux2); // libera memoria
    free(aux3); // libera memoria
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