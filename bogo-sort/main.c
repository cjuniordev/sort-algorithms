#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main()
{
  int len, ate;

  printf("Tamanho da lista: ");
  scanf("%d", &len);
  
  int lista[len];

  printf("Gerar numeros aleatorios de 0 ate: ");
  scanf("%d", &ate);

  gerarListaAleatoria(lista, len, ate+1);

  printf("Lista Desordenada:\n");

  imprimeLista(lista, len);

  bogoSort(lista, len); // Chamada da função que aplica o metodo bogosort

  printf("\nLista Ordenada:\n");

  imprimeLista(lista, len);

  printf("\n");
}
