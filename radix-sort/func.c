#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void radixSort(int list[], int len) {
    int i;
    int *b;
    int maior = list[0];
    int exp = 1;

    b = (int *)calloc(len, sizeof(int));

    for (i = 0; i < len; i++) {
        if (list[i] > maior)
    	    maior = list[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < len; i++)
    	    bucket[(list[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = len - 1; i >= 0; i--)
    	    b[--bucket[(list[i] / exp) % 10]] = list[i];
    	for (i = 0; i < len; i++)
    	    list[i] = b[i];
    	exp *= 10;
    }

    free(b);
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