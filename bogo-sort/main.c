#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"

int main(){
  int len = 10;
  int *lista = (int *)calloc(len, sizeof(int));
  gerarListaAleatoria(lista, len, 0, 10+1);
  clock_t tInicio;
  tInicio = clock(); // inicia a marcação do tempo 
  bogoSort(lista, len); // Chamada da função que aplica o metodo bogosort
  printf("exp 1 | Tempo de execução: %ldms\n", ((clock() - tInicio) / (CLOCKS_PER_SEC / 1000)));
}
