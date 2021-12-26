#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"

int main()
{
  int len, from, to;

  printf("Tamanho da lista: ");
  scanf("%d", &len);
  
  int list[len];

  printf("Gerar numeros aleatorios de: ");
  scanf("%d", &from);
  
  printf("Ate: ");
  scanf("%d", &to);

  gerarListaAleatoria(list, len, from, to+1);

  printf("Lista Desordenada:\n");

  imprimeLista(list, len);

  printf("\nLista Ordenada:\n");

  radixSort(list, len); //Chamada da função que aplica o metodo radixSort

  imprimeLista(list, len);

  printf("\n");
}
