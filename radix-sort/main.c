#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main()
{
  int list[] = { 4, 1, 3, 0, 0, -10, -5, -68, 10 }; //Variavel contendo a lista
  int len = sizeof(list)/sizeof(list[0]); //Variavel contendo o comprimento da lista

  printf("Lista Desordenada:\n");

  imprimeLista(list, len);

  printf("\nLista Ordenada:\n");

  radixSort(list, len); //Chamada da função que aplica o metodo radixSort

  imprimeLista(list, len);

  printf("\n");
}
