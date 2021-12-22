#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "func.h"

int main()
{
  int lista[] = { 4, 1, 3, 7, 8, 10, -5 };
  int comprimento = sizeof(lista)/sizeof(lista[0]);
  int num = 0;

  printf("Lista Desordenada:\n");

  imprimeLista(lista, comprimento);

  printf("\nLista Ordenada:\n");

  bogoSort(lista, comprimento);

  imprimeLista(lista, comprimento);
}
