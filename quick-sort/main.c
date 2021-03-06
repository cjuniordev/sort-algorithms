#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"

int main(){
  
  int len = 10;
  clock_t tInicio;
  int *lista = (int *)calloc(len, sizeof(int));
  // exp 1;
  gerarListaAleatoria(lista, len, 0, 10);
  tInicio = clock(); // inicia a marcação do tempo 
  quickSort(lista, 0, len); // Chamada da função que aplica o metodo quicksort
  printf("exp 1 | Tempo de execução: %.4fms\n", ((double)(clock() - tInicio) / (CLOCKS_PER_SEC / 1000)));
  free(lista);
  
  // exp 2.1
  len = 1000;
  lista = (int *)calloc(len, sizeof(int));
  gerarListaAleatoria(lista, len, -1000, 1000);
  tInicio = clock(); // inicia a marcação do tempo 
  quickSort(lista, 0, len); // Chamada da função que aplica o metodo quicksort
  printf("exp 2.1 | Tempo de execução: %.4fms\n", ((double)(clock() - tInicio) / (CLOCKS_PER_SEC / 1000)));
  free(lista);

  // exp 2.2
  lista = (int *)calloc(len, sizeof(int));
  gerarListaCrescente(lista, len);
  tInicio = clock(); // inicia a marcação do tempo 
  quickSort(lista, 0, len); // Chamada da função que aplica o metodo quicksort
  printf("exp 2.2 | Tempo de execução: %.4fms\n", ((double)(clock() - tInicio) / (CLOCKS_PER_SEC / 1000)));
  free(lista);

  // exp 2.3
  lista = (int *)calloc(len, sizeof(int));
  gerarListaDecrescente(lista, len);
  tInicio = clock(); // inicia a marcação do tempo 
  quickSort(lista, 0, len); // Chamada da função que aplica o metodo quicksort
  printf("exp 2.3 | Tempo de execução: %.4fms\n", ((double)(clock() - tInicio) / (CLOCKS_PER_SEC / 1000)));
  free(lista);

  // exp 3.1
  len = 10000;
  lista = (int *)calloc(len, sizeof(int));
  gerarListaAleatoria(lista, len, -99999, 99999);
  tInicio = clock(); // inicia a marcação do tempo 
  quickSort(lista, 0, len); // Chamada da função que aplica o metodo quicksort
  printf("exp 3.1 | Tempo de execução: %.4fms\n", ((double)(clock() - tInicio) / (CLOCKS_PER_SEC / 1000)));
  free(lista);

  // exp 3.2
  lista = (int *)calloc(len, sizeof(int));
  gerarListaCrescente(lista, len);
  tInicio = clock(); // inicia a marcação do tempo 
  quickSort(lista, 0, len); // Chamada da função que aplica o metodo quicksort
  printf("exp 3.2 | Tempo de execução: %.4fms\n", ((double)(clock() - tInicio) / (CLOCKS_PER_SEC / 1000)));
  free(lista);

  // exp 3.3
  lista = (int *)calloc(len, sizeof(int));
  gerarListaDecrescente(lista, len);
  tInicio = clock(); // inicia a marcação do tempo 
  quickSort(lista, 0, len); // Chamada da função que aplica o metodo quicksort
  printf("exp 3.3 | Tempo de execução: %.4fms\n", ((double)(clock() - tInicio) / (CLOCKS_PER_SEC / 1000)));
  free(lista);

  return 0;
}
