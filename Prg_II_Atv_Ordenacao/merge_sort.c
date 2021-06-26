/*
 * merge_sort.c
 *
 *  Created on: 16 de abr de 2021
 *      Author: MATHEUS
 */
#include <stdlib.h>

#include "merge_sort.h"
#include "quick_sort.h"


void funde(float *vetor,int esq, int meio, int dir, float *tempvet){

	int i = esq, j = esq, k = meio+1;

	while(j<= meio && k<= dir){
		if(vetor[j]<vetor[k]) tempvet[i++] = vetor[j++];
		else tempvet[i++] = vetor[k++];
	}

	while(j<=meio){
		tempvet[i++] = vetor[j++];
	}
	for(i=esq;i<k;i++){

		vetor[i]=tempvet[i];
	}

}

void merge_sort(float *vetor, int esq, int dir,float *tempvet){

	int meio;
	if(esq<dir){

		meio = (esq+dir)/2;

		merge_sort(vetor,esq,meio,tempvet);
		merge_sort(vetor,meio+1,dir,tempvet);

		funde(vetor,esq,meio,dir,tempvet);
	}
}

