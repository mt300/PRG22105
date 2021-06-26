/*
 * heap_sort.h
 *
 *  Created on: 16 de abr de 2021
 *      Author: MATHEUS
 */

#ifndef HEAP_SORT_H_
#define HEAP_SORT_H_


int pai(int i);

int esquerda(int i);

int direita(int i);

void heap_sort(float *vetor, int tamanho);

void max_heapfy(float *heap, int i , int n);




#endif /* HEAP_SORT_H_ */
