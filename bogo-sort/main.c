#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"

int main()
{
  int len, from, to;

  printf("Tamanho da lista: ");
  scanf("%d", &len);
  
  int lista[len];

  printf("Gerar numeros aleatorios de: ");
  scanf("%d", &from);
  
  printf("Ate: ");
  scanf("%d", &to);

  gerarListaAleatoria(lista, len, from, to+1);

  printf("Lista Desordenada:\n");

  imprimeLista(lista, len);

  bogoSort(lista, len); // Chamada da função que aplica o metodo bogosort

  printf("\nLista Ordenada:\n");

  imprimeLista(lista, len);

  printf("\n");
}
