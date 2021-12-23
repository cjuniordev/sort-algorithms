#include <stdio.h>
#include "func.h"

int main()
{
    int list[] = {2, 4, 6, 7, 9, 1, 4, 6, 9, 0}; // Declarando lista desordenada
    int len = sizeof(list)/sizeof(list[0]); // Variavel contendo o comprimento da lista

    printf("Lista desordenada:\n");

    imprimeLista(list, len);
    
    quickSort(list, 0, len); // Chamada da função que aplica o metodo bogosort

    printf("\nLista ordenada:\n");

    imprimeLista(list, len);

    return 0;
}
