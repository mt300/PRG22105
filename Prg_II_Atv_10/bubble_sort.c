/*
 * bubble_sort.c
 *
 *  Created on: 8 de abr de 2021
 *      Author: MATHEUS
 */
#include <stdio.h>
#include <stdlib.h>

#include "bubble_sort.h"

void bubble_sort(int *vetor, int tam)
{
    int i, j, aux;

    for (i = tam; i > 1; i--) {
        for (j=0; j<i-1; j++) {
            if (vetor[j]>vetor[j+1]) {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}
