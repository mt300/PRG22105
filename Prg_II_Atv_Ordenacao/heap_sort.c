/*
 * heap_sort.c
 *
 *  Created on: 16 de abr de 2021
 *      Author: MATHEUS
 */
#include <stdlib.h>

#include "heap_sort.h"
#include "quick_sort.h"

int pai(int i){
	return (i-1)/2;
}

int esquerda(int i){
	return 2*i +1;
}

int direita(int i){
	return 2*i+2;
}



void max_heapfy(float *heap, int i , int n){

	int e = esquerda(i);
	int d = direita(i);
	int maior;

	if(e<n && heap[e]>heap[i]) maior = e;
	else maior = i;

	if(d<n && heap[d]>heap[maior]) maior = d;

	if(maior != i){
		swap(heap,i,maior);
		max_heapfy(heap, maior,n);
	}

}

void heap_sort(float *vetor,int tamanho){

	int i;

	for(i = tamanho/2 -1; i>=0; i--){
		max_heapfy(vetor,i,tamanho);
	}

	for(i = tamanho-1; i>=1; i--){
		swap(vetor,0,i);

		max_heapfy(vetor,0, --tamanho);
	}
}
