#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void quickSort(int *list, int init, int end){
    int index_pivo = (init+end)/2; // Pega index do pivo, que é o index do meio
    int pivo = list[index_pivo]; // Pega pivo da lista
    int i = init;
    int j = end-1;
    int temp;

    while(i <= j){
        while (list[i] < pivo && i < end){ // Verifica se todos numeros antes do pivo sao menores que ele
            i++; // Incrementa i
        } 
        while(list[j] > pivo && j > init){ // Verifica se todos numeros apos o pivo sao maiores que ele
			j--; // Decrementa j
		}
        if(i <= j){ // Se i for menor ou igual a j
			temp = list[i]; // Pegando posicão i da lista
			list[i] = list[j]; // A posiçao i recebe a posiçao j
			list[j] = temp; // A posição j recebe a posiçao i
			i++;
			j--;
		} // Até aqui a lista esta ordenada entre maiores e menores que o pivo

        // Agora pegamos essa lista subdividida em duas partes nao ordenadas, e refazemos o processo recursivamente
        if(j > init)
		    quickSort(list, init, j+1);
	    if(i < end)
		    quickSort(list, i, end);
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

void gerarListaAleatoria(int *lista, int len, int n){
  for(int i=0;i<len;i++)
  {
    lista[i]=(rand()%n);
  }
}