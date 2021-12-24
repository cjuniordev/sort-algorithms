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

    printf("Lista desordenada:\n");

    imprimeLista(lista, len);
    
    quickSort(lista, 0, len); // Chamada da função que aplica o metodo bogosort

    printf("\nLista ordenada:\n");

    imprimeLista(lista, len);

    return 0;
}
