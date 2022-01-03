#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"

int main()
{
  int len = 10;
  int *lista = (int *)calloc(len, sizeof(int));
  // exp 1
  clock_t tInicio;
  tInicio = clock(); // inicia a marcação do tempo 
  gerarListaAleatoria(lista, len, 0, 10+1);
  radixSort(lista, len); // Chamada da função que aplica o metodo radixSort
  printf("exp 1 | Tempo de execução: %ldms\n", ((clock() - tInicio) / (CLOCKS_PER_SEC / 1000)));

  // exp 2.1
  len = 1000;
  lista = (int *)calloc(len, sizeof(int));
  tInicio = clock(); // inicia a marcação do tempo 
  gerarListaAleatoria(lista, len, -1000, 1000+1);
  radixSort(lista, len); // Chamada da função que aplica o metodo radixSort
  printf("exp 2.1 | Tempo de execução: %ldms\n", ((clock() - tInicio) / (CLOCKS_PER_SEC / 1000)));

  // exp 2.2
  len = 1000;
  lista = (int *)calloc(len, sizeof(int));
  tInicio = clock(); // inicia a marcação do tempo 
  gerarListaCrescente(lista, len);
  radixSort(lista, len); // Chamada da função que aplica o metodo radixSort
  printf("exp 2.2 | Tempo de execução: %ldms\n", ((clock() - tInicio) / (CLOCKS_PER_SEC / 1000)));

  // exp 2.3
  len = 1000;
  lista = (int *)calloc(len, sizeof(int));
  tInicio = clock(); // inicia a marcação do tempo 
  gerarListaDecrescente(lista, len);
  radixSort(lista, len); // Chamada da função que aplica o metodo radixSort
  printf("exp 2.3 | Tempo de execução: %ldms\n", ((clock() - tInicio) / (CLOCKS_PER_SEC / 1000)));

  // exp 3.1
  len = 10000;
  lista = (int *)calloc(len, sizeof(int));
  tInicio = clock(); // inicia a marcação do tempo 
  gerarListaAleatoria(lista, len, -99999, 99999+1);
  radixSort(lista, len); // Chamada da função que aplica o metodo radixSort
  printf("exp 3.1 | Tempo de execução: %ldms\n", ((clock() - tInicio) / (CLOCKS_PER_SEC / 1000)));

  // exp 3.2
  len = 10000;
  lista = (int *)calloc(len, sizeof(int));
  tInicio = clock(); // inicia a marcação do tempo 
  gerarListaCrescente(lista, len);
  radixSort(lista, len); // Chamada da função que aplica o metodo radixSort
  printf("exp 3.2 | Tempo de execução: %ldms\n", ((clock() - tInicio) / (CLOCKS_PER_SEC / 1000)));

  // exp 3.3
  len = 10000;
  lista = (int *)calloc(len, sizeof(int));
  tInicio = clock(); // inicia a marcação do tempo 
  gerarListaDecrescente(lista, len);
  radixSort(lista, len); // Chamada da função que aplica o metodo radixSort
  printf("exp 3.3 | Tempo de execução: %ldms\n", ((clock() - tInicio) / (CLOCKS_PER_SEC / 1000)));

  return 0;
}
