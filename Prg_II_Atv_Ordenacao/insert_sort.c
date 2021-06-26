/*
 * insert_sort.c
 *
 *  Created on: 13 de abr de 2021
 *      Author: MATHEUS
 */


#include <stdio.h>
#include <stdlib.h>

#include "insert_sort.h"
#include "quick_sort.h"

void insert_sort(float *vetor, int n){
	int i,j;
	for(i=1;i<n;i++){
		for(j=i;j>0 && vetor[j-1]>vetor[j];j--){
			swap(vetor,j,j-1);
		}
	}
}


void bin_insert_sort(float *vetor,int n){
	int i,j, tmp,meio,esq,dir;

	for(i=1;i<n;i++){
		tmp = vetor[i];
		esq = 0;
		dir = i;

		while(esq<dir){

			meio = (esq+dir)/2;

			if(tmp >= vetor[meio]){
				esq = meio+1;
			}
			else{
				dir = meio;
			}
		}
		for(j=i;j>esq;j--){
			swap(vetor,j-1,j);
		}
	}
}
