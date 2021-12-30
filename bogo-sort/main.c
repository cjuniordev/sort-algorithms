#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"

int main(){

  // aqui comeca os experimentos
  printf("Experimento 1:\n");
  int len = 10;
  int lista[len];
  gerarListaAleatoria(lista, len, 0, 10+1);

  printf("Lista Desordenada:\n");
  imprimeLista(lista, len);

  bogoSort(lista, len); // Chamada da função que aplica o metodo bogosort

  printf("\nLista Ordenada:\n");
  imprimeLista(lista, len);

  printf("\n");
}
