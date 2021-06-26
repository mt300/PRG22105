/*
 * quick_sort.h
 *
 *  Created on: 9 de abr de 2021
 *      Author: MATHEUS
 */

#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

void swap(float *vetor, int ind_1, int ind_2);
int med_3(float *vetor, int esq, int dir);
int part(float *vetor,int ind_e, int ind_d);
void quick_sort(float *vetor, int ind_esq, int ind_dir);



#endif /* QUICK_SORT_H_ */
