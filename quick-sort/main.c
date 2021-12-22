#include <stdio.h>
#include "func.h"

void sort(int *list, int init, int end);

int main()
{
    int list[10] = {2, 4, 6, 7, 9, 1, 4, 6, 9, 0};

    printf("Lista desordenada: [ ");
    for(int i = 0; i < 10; i++){
        if(i==9){
            printf("%d ]\n", list[i]);
        } else{
            printf("%d, ", list[i]);
        }   
	}
    
    sort(list, 0, 10);

    printf("Lista ordenada: [ ");
    for(int i = 0; i < 10; i++){
        if(i==9){
            printf("%d ]\n", list[i]);
        } else{
            printf("%d, ", list[i]);
        }   
	}

    return 0;
}

void sort(int *list, int init, int end){
    int index_pivo = (init+end)/2;
    int pivo = list[index_pivo];
    int i = init;
    int j = end-1;
    int temp;

    while(i <= j){
        while (list[i] < pivo && i < end){
            i++;
        } 
        while(list[j] > pivo && j > init){
			j--;
		}
        if(i <= j){
			temp = list[i];
			list[i] = list[j];
			list[j] = temp;
			i++;
			j--;
		}
        if(j > init)
		    sort(list, init, j+1);
	    if(i < end)
		    sort(list, i, end);
    }
}