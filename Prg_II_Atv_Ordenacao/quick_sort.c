/*
 * quick_sort.c
 *
 *  Created on: 9 de abr de 2021
 *      Author: MATHEUS
 */

#include <stdio.h>
#include <stdlib.h>

#include "quick_sort.h"


 void swap(float *vetor, int ind_1, int ind_2){
	float aux;

	aux = vetor[ind_1];
	vetor[ind_1] = vetor[ind_2];
	vetor[ind_2] = aux;
}

int med_3(float *vetor, int esq, int dir){
	int med = (esq + dir)/2;
	if (vetor[dir] < vetor[esq]){
		swap(vetor,esq,dir);
	}
	if (vetor[med]<vetor[esq]){
		swap(vetor,esq,med);
	}
	if (vetor[dir]<vetor[med]){
		swap(vetor,med,dir);
	}
	return med;
}

int part(float *vetor,int ind_e, int ind_d){
	int med = med_3(vetor, ind_e, ind_d);
	float pivo = vetor[med];
	int i= ind_e-1;
	int j =ind_d+1;

	for(;;){
		do{
			i = i +1;
		}while(vetor[i]<pivo);
		do{
			j=j-1;
		}while(vetor[j]>pivo);
		if(i>=j){
			return j;
		}
		swap(vetor,i,j);
	}

}
void quick_sort(float *vetor, int ind_esq, int ind_dir){
	int p;
	if(ind_esq < ind_dir){
		p = part(vetor,ind_esq,ind_dir);
		quick_sort(vetor,ind_esq,p);
		quick_sort(vetor,p+1,ind_dir);
	}
}
