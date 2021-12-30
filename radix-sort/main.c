#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"

int main()
{
  int len = 10;
  int *lista = (int *)calloc(len, sizeof(int));
  // exp 1
  printf("Experimento 1:\n");
  gerarListaAleatoria(lista, len, 0, 10+1);

  printf("Lista desordenada:\n");
  imprimeLista(lista, len);
  
  radixSort(lista, len); // Chamada da função que aplica o metodo radixSort

  printf("\nLista ordenada:\n");
  imprimeLista(lista, len);

  // exp 2.1
  len = 1000;
  lista = (int *)calloc(len, sizeof(int));
  printf("\nExperimento 2.1:\n");
  gerarListaAleatoria(lista, len, -1000, 1000+1);

  printf("Lista desordenada:\n");
  imprimeLista(lista, len);
  
  radixSort(lista, len); // Chamada da função que aplica o metodo radixSort

  printf("\nLista ordenada:\n");
  imprimeLista(lista, len);

  // exp 2.2
  len = 1000;
  lista = (int *)calloc(len, sizeof(int));
  printf("\nExperimento 2.2:\n");
  gerarListaCrescente(lista, len);

  printf("Lista desordenada:\n");
  imprimeLista(lista, len);

  radixSort(lista, len); // Chamada da função que aplica o metodo radixSort

  printf("\nLista ordenada:\n");
  imprimeLista(lista, len);

  // exp 2.3
  len = 1000;
  lista = (int *)calloc(len, sizeof(int));
  printf("\nExperimento 2.2:\n");
  gerarListaDecrescente(lista, len);

  printf("Lista desordenada:\n");
  imprimeLista(lista, len);

  radixSort(lista, len); // Chamada da função que aplica o metodo radixSort

  printf("\nLista ordenada:\n");
  imprimeLista(lista, len);

  // exp 3.1
  len = 10000;
  lista = (int *)calloc(len, sizeof(int));
  printf("\nExperimento 3.1:\n");
  gerarListaAleatoria(lista, len, -99999, 99999+1);

  printf("Lista desordenada:\n");
  imprimeLista(lista, len);

  radixSort(lista, len); // Chamada da função que aplica o metodo radixSort

  printf("\nLista ordenada:\n");
  imprimeLista(lista, len);

  // exp 3.2
  len = 10000;
  lista = (int *)calloc(len, sizeof(int));
  printf("\nExperimento 3.2:\n");
  gerarListaCrescente(lista, len);

  printf("Lista desordenada:\n");
  imprimeLista(lista, len);

  radixSort(lista, len); // Chamada da função que aplica o metodo radixSort

  printf("\nLista ordenada:\n");
  imprimeLista(lista, len);

  // exp 3.3
  len = 10000;
  lista = (int *)calloc(len, sizeof(int));
  printf("\nExperimento 3.3:\n");
  gerarListaDecrescente(lista, len);

  printf("Lista desordenada:\n");
  imprimeLista(lista, len);

  radixSort(lista, len); // Chamada da função que aplica o metodo radixSort

  printf("\nLista ordenada:\n");
  imprimeLista(lista, len);

  return 0;
}
