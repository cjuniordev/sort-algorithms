#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "func.h"
 
int estaOrdenado(int *lista, int n, int **i)
{
  while ( --n >= 1 ) 
  {
    if ( lista[n] < lista[n-1] )
    {
      **i++;
      return 0;
    }
  }
  return 1;
}
 
void ordenar(int *lista, int n)
{
  int temp, aleatorio;
  for(int i=0; i < n; i++) 
  {
    temp = lista[i];
    aleatorio = rand() % n;
    lista[i] = lista[aleatorio];
    lista[aleatorio] = temp;
  }
}
 
void bogoSort(int *lista, int n, int *i)
{
  while ( !estaOrdenado(lista, n, &i) )
  {
    ordenar(lista, n);
  }
}