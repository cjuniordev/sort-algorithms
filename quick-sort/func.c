#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"

void trocaNumeros(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

int particao(int *list, int init, int end){
  // Pega o número mais a direita da lista como o pivô
  int pivo = list[end];
  
  // Ponteiro para o maior elemento
  int i = init - 1;

  // Passa por todos os números da lista comparando-os com o pivô
  for (int j = init; j <= end; j++) {
    if (list[j] < pivo) {
      // se um numero menor q i for encontra aumenta i
      i++;
      // e troca os números
      trocaNumeros(&list[i], &list[j]);  
    }
  }

  // troca o numero pivô com o maior número apontado por i
  trocaNumeros(&list[i + 1], &list[end]);
   
  // retorna o ponteiro da partição
  return i+1;
}

void quickSort(int *list, int init, int end) {
  if (init < end) {
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pivo = particao(list, init, end);
    
    // recursive call on the left of pivot
    quickSort(list, init, pivo - 1);
    
    // recursive call on the right of pivot
    quickSort(list, pivo + 1, end);
  }
}

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
  n++;
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