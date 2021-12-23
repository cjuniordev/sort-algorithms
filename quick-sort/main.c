#include <stdio.h>
#include "func.h"

int main()
{
    int list[] = {2, 4, 6, 7, 9, 1, 4, 6, 9, 0}; // declarando lista desordenada
    int len = sizeof(list)/sizeof(list[0]); //Variavel contendo o comprimento da lista

    printf("Lista desordenada:\n");
    
    imprimeLista(list, len);
    
    quickSort(list, 0, len); // ordena lista

    printf("\nLista ordenada:\n");

    imprimeLista(list, len);

    return 0;
}
