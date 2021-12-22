#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "func.h"

int main()
{
  int lista[] = { 4, 1, 3, 7, 8, 10, -5 }; //Variavel contendo a lista
  int comprimento = sizeof(lista)/sizeof(lista[0]); //Variavel contendo o comprimento da lista

  printf("Lista Desordenada:\n");

  imprimeLista(lista, comprimento);

  printf("\nLista Ordenada:\n");

  bogoSort(lista, comprimento); //Chamada da função que aplica o metodo bogosort

  imprimeLista(lista, comprimento);

  printf("\n");
}
