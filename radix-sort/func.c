#include <stdio.h>
#include <stdlib.h>
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

void zeraLista(int *lista, int n){
    for(int i=0; i<n; i++){
        lista[i] = 0;
    }
}

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
    while(q > 0){
        countingSort(lista, n, divisor, aux);
        divisor *= 10; // dividor multiplo de 10 para ir pegando sempre a proxima casa decimal
        q /= 10; // diminui a quantidade de casas do maior numero
    }
    free(aux); // libera memoria
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