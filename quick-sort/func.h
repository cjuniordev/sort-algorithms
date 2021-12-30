#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// cabeçalho das funções -----
void quickSort(int *list, int init, int end);
void imprimeLista(int *lista, int n);
void gerarListaAleatoria(int *lista, int len, int m, int n);
void gerarListaCrescente(int *lista, int len);
void gerarListaDecrescente(int *lista, int len);