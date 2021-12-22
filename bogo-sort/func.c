#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "func.h"
 
int estaOrdenado(int *lista, int n) // Funcao que verifica se a lista esta ordenada
{
  while ( --n >= 1 )  // Enquanto --comprimento da lista for maior ou igual a 1
  {
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
  for (int i = 0; i < n; i++) // Estrutura de repetição que passa por toda a lista e imprime seus valores
  {
    printf("%d ", lista[i]);  
  }
}