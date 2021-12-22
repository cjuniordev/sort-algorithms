#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "func.h"

int main()
{
  int lista[] = { 4, 1, 3, 7, 8, 10, -5 };
  int comprimento = sizeof(lista)/sizeof(lista[0]);
  int num = 0;

  printf("Lista Original:\n");

  for (int i = 0; i < comprimento; i++)
  {
    printf("%d%s", lista[i], i == comprimento - 1 ? "\n" : " ");  
  }

  printf("\nLista Organizada:\n");

  bogoSort(lista, 7, &num);

  for (int i=0; i < 7; i++)
  {
    printf("%d ", lista[i]);
  }

  printf("\n Numero de vezes que o Metodo de Ordenacao foi usado: %d", num);
}
