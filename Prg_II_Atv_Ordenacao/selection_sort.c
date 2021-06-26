/*
 * selection_sort.c
 *
 *  Created on: 16 de abr de 2021
 *      Author: MATHEUS
 */

#include <stdlib.h>
#include <stdio.h>

#include "selection_sort.h"
#include "quick_sort.h"


void selection_sort(float *vetor, int n){

	int max,i,j;

	for(i=n; i>1;i--){

		max = 0;
		for(j=1;j<i;j++){
			if(vetor[j]>vetor[max]) max = j;
		}
		swap(vetor,i-1,max);
	}

}
