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

    printf("Lista desordenada:\n");

    imprimeLista(lista, len);
    
    quickSort(lista, 0, len); // Chamada da função que aplica o metodo bogosort

    printf("\nLista ordenada:\n");

    imprimeLista(lista, len);

    return 0;
}
