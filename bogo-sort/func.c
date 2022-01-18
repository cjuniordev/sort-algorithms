#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"
 
int estaOrdenado(int *lista, int n) // Funcao que verifica se a lista esta ordenada
{
  while ( n >= 2 )  // Enquanto comprimento da lista for maior ou igual a 2
  {
    
    --n; // Diminuímos o valor dele em um e verificamos

    if ( lista[n] < lista[n-1] ) // Se o valor atual da lista for menor que o valor anterior
    {
      return 0; // Retorna falso
    }
  }
  return 1; // Caso contrário, retorna verdadeiro
}
 
void ordenar(int *lista, int n) // Funcao que ordena a lista
{
  int temp, aleatorio;
  for(int i=0; i < n; i++)
  {
    temp = lista[i]; // Variavel auxiliar = valor atual da lista
    aleatorio = rand() % n; // Pega um valor aleatorio que nunca ultrapassa o tamanho da lista
    lista[i] = lista[aleatorio]; // Valor atual da lista = Valor aleatorio da lista
    lista[aleatorio] = temp; // Valor aleatorio da lista = variavel auxiliar
  }
}
 
void bogoSort(int *lista, int n) // Funcao que aplica o metodo bogosort
{
  while ( !estaOrdenado(lista, n) ) // Enquanto a lista não está ordenada
  {
    ordenar(lista, n); // Ordena ela
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
  for(int j = (n-m); j > 0; j -= RAND_MAX){
    for(int i=0;i<len;i++)
    {
      lista[i]+=(rand()%j); //gera um número aleatório entre 0 e j, j vezes
      //devido ao limite que um número aleatório pode ser gerado: RAND_MAX = 32767
      //listas muito grandes, como as dos experimentos 3.1 + não podem ser geradas
      //então temos que gerar valores aleatórios diversas vezes para satisfazer isso
    }
  }
    for(int i=0;i<len;i++)
    {
      lista[i]+=m; //adiciona o número m (valor mínimo) na lista para que seu valor nunca seja menor que ele
      //isso foi feito para que possamos gerar números negativos ou com o chão sendo > 0
    }
}