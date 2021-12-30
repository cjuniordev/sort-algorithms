#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"
 

void imprimeLista(int *lista, int n) // Funcao que imprime a lista, para evitar repetição de codigo
{
  printf("[ ");
  for (int i = 0; i < n; i++) // Estrutura de repetição que passa por toda a lista e imprime seus valores
  {
    if(i==(n-1)){
            printf("%d ]\n", lista[i]);
        } else{
            printf("%d, ", lista[i]);
        }  
  }
}

void gerarListaAleatoria(int *lista, int len, int m, int n){
  srand( (unsigned)time(NULL) );
  for(int i=0;i<len;i++)
  {
    lista[i]=((rand()%(n-m))+m);
  }
}

void gerarListaCrescente(int *lista, int len)
{
  for(int i = 0; i < len; i++) lista[i] = i+1;
}

void gerarListaDecrescente(int *lista, int len)
{
  for(int i = 0; i <= len; i++) lista[len-i] = i;
}