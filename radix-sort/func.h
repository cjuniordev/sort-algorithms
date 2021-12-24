#include <stdio.h>
#include <stdlib.h>

// cabeçalho das funções -----
int pegaDigito(int numero, int divisor);
int maximo(int lista[], int n);
void juntaVetores(int *v, int *inicial, int *final, int n);
void negativaLista(int *lista, int n);
void inverteLista(int *lista, int n);
void zeraLista(int *lista, int n);
void countingSort(int *lista, int n, int divisor, int *aux);
void radixSort(int *lista, int n);
void imprimeLista(int *lista, int n);