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
  
  // Ponteiro para o maior elemento da lista
  int x = init - 1;

  // Passa por todos os números da lista comparando-os com o pivô
  for (int i = init; i <= end; i++) {
    if (list[i] < pivo) {
      // se um numero menor que x for encontrado aumenta x
      x++;
      // e troca os números
      trocaNumeros(&list[x], &list[i]);  
    }
  }

  // troca o numero pivô com o maior número apontado por x
  trocaNumeros(&list[x + 1], &list[end]);
   
  // retorna o ponteiro da partição
  return x+1;
}

void quickSort(int *list, int init, int end) {
  if (init < end) {
    // Primeiro encontramos o elemento pivô para que aqueles menores
    // que o pivô estejam a esquerda dele e maiores a direita dele.
    int pivo = particao(list, init, end);
    
    quickSort(list, init, pivo - 1); // Chama novamente a função para os elementos menores que o pivô
    
    quickSort(list, pivo + 1, end); // Chama novamente a função para os elementos maiores que o pivô
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
  srand( (unsigned)time(NULL) ); // Gera números semi-aleatórios baseado em algumas coisas do computador
  n++; //aumenta n em 1 devido a como a função rand funciona
  for(int i=0;i<len;i++)
  {
    lista[i]=((rand()%(n-m))+m); //gera um número aleatório entre (n-m) e depois soma m nele
    //isso foi feito para que possamos gerar números negativos ou com o chão sendo > 0
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