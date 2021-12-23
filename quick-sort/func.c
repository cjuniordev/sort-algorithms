#include <stdio.h>
#include "func.h"

void quickSort(int *list, int init, int end){
    int index_pivo = (init+end)/2; // pega index do pivo, que é o index do meio
    int pivo = list[index_pivo]; // pega pivo da lista
    int i = init;
    int j = end-1;
    int temp;

    while(i <= j){
        while (list[i] < pivo && i < end){ // verifica se todos numeros antes do pivo sao menores que ele
            i++; // incrementa i
        } 
        while(list[j] > pivo && j > init){ // verifica se todos numeros apos o pivo sao maiores que ele
			j--; // decrementa j
		}
        if(i <= j){ // se i for menor ou igual a j
			temp = list[i]; // pegando posicão i da lista
			list[i] = list[j]; // a posiçao i recebe a posiçao j
			list[j] = temp; // a posição j recebe a posiçao i
			i++;
			j--;
		} // até aqui a lista esta ordenada entre maiores e menores que o pivo

        // agora pegamos essa lista subdividida em duas partes nao ordenadas, e refazemos o processo recursivamente
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