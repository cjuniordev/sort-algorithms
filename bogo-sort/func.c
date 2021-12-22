#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "func.h"
 
int estaOrdenado(int *lista, int n)
{
  while ( --n >= 1 ) 
  {
    if ( lista[n] < lista[n-1] )
    {
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
 
void bogoSort(int *lista, int n)
{
  while ( !estaOrdenado(lista, n) )
  {
    ordenar(lista, n);
  }
}

void imprimeLista(int *lista, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", lista[i]);  
  }
}