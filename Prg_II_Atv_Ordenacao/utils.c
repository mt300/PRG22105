/*
 * utils.c
 *
 *  Created on: 8 de abr de 2021
 *      Author: MATHEUS
 */



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "bubble_sort.h"
#include "quick_sort.h"
#include "insert_sort.h"
#include "selection_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"

#define LACO 20

void exibir_vetor(float *vetor, int tam){

	int i;

	for (i=0; i < tam; i++)
		printf("[%d] \t %.2f\n", i, vetor[i]);

	puts("---------------------------");

}

void completar_vetor(float *vetor, int tam){

	int i;

	for (i=0; i < tam; i++)
		vetor[i] = rand()/(float)(RAND_MAX/10000);
}

float media(int tam, float *vet){
	int i;
	float media=0;
	for (i =0;i<tam;i++){
		media = media+vet[i];
	}
	media =(float)media/(float)tam;

	return media;
}

void medir_tempo( int tam, int op){

	int i;
	FILE *fp = fopen("relatorio.csv","a");
	clock_t t[LACO];
	float *vet,*tempvet;
	float duration[LACO];
	float mean;
	vet = (float *)malloc(sizeof(float) * tam);
	tempvet  = (float *)malloc(sizeof(float)*tam);

	switch(op){
	case 1:
		for(i =0; i<LACO;i++){
			sleep(1);
			completar_vetor(vet, tam);
			//exibir_vetor(vet,tam);
			t[i] = clock();
			bubble_sort(vet,tam);
			t[i] = clock() -t[i];
			duration[i] = (float)t[i]/CLOCKS_PER_SEC;
			//printf("Tempo de execucao (%d): %.2f segundos\n",i,duration[i]);
			//exibir_vetor(vet,tam);



		}
		mean = media(LACO,duration);
		fprintf(fp,"Bubble_Sort,%.2fs\n",mean);
		break;
	case 2:
		for(i =0; i<LACO;i++){
			sleep(1);
			completar_vetor(vet, tam);
			//exibir_vetor(vet,tam);
			t[i] = clock();
			quick_sort(vet,0,tam);
			t[i] = clock() -t[i];
			duration[i] = (float)t[i]/CLOCKS_PER_SEC;
			printf("Tempo de execucao (%d): %.2f segundos\n",i,duration[i]);
			//exibir_vetor(vet,tam);



		}
		mean = media(LACO,duration);
		fprintf(fp,"Quick_Sort,%.2fs\n",mean);
		break;
	case 3:
		for(i =0; i<LACO;i++){
			sleep(1);
			completar_vetor(vet, tam);
			//exibir_vetor(vet,tam);
			t[i] = clock();
			insert_sort(vet,tam);
			t[i] = clock() -t[i];
			duration[i] = (float)t[i]/CLOCKS_PER_SEC;
			//printf("Tempo de execucao (%d): %.2f segundos\n",i,duration[i]);
			//exibir_vetor(vet,tam);



		}
		mean = media(LACO,duration);
		fprintf(fp,"Insert_Sort,%.2fs\n",mean);
		break;
	case 4:
		for(i =0; i<LACO;i++){
			sleep(1);

			completar_vetor(vet, tam);
			//exibir_vetor(vet,tam);
			t[i] = clock();
			bin_insert_sort(vet,tam);
			t[i] = clock() -t[i];
			duration[i] = (float)t[i]/CLOCKS_PER_SEC;
			//printf("Tempo de execucao (%d): %.2f segundos\n",i,duration[i]);
			//exibir_vetor(vet,tam);



		}
		mean = media(LACO,duration);
		fprintf(fp,"Binary_Insert_Sort,%.2fs\n",mean);
		break;
	case 5:
		for(i =0; i<LACO;i++){
			sleep(1);
			completar_vetor(vet, tam);
			//exibir_vetor(vet,tam);
			t[i] = clock();
			selection_sort(vet,tam);
			t[i] = clock() -t[i];
			duration[i] = (float)t[i]/CLOCKS_PER_SEC;
			//printf("Tempo de execucao (%d): %.2f segundos\n",i,duration[i]);
			//exibir_vetor(vet,tam);



		}
		mean = media(LACO,duration);
		fprintf(fp,"Selection_Sort,%.2fs\n",mean);
		break;
	case 6:
		for(i =0; i<LACO;i++){
			sleep(1);
			completar_vetor(vet, tam);
			//exibir_vetor(vet,tam);
			t[i] = clock();
			merge_sort(vet,0,tam-1,tempvet);
			t[i] = clock() -t[i];
			duration[i] = (float)t[i]/CLOCKS_PER_SEC;
			//printf("Tempo de execucao (%d): %.2f segundos\n",i,duration[i]);
			//exibir_vetor(vet,tam);



		}
		mean = media(LACO,duration);
		fprintf(fp,"Merge_Sort,%.2fs\n",mean);
		break;
	case 7:
		for(i =0; i<LACO;i++){
			sleep(1);

			completar_vetor(vet, tam);
			//exibir_vetor(vet,tam);
			t[i] = clock();
			heap_sort(vet,tam);
			t[i] = clock() -t[i];
			duration[i] = (float)t[i]/CLOCKS_PER_SEC;
			//printf("Tempo de execucao (%d): %.2f segundos\n",i,duration[i]);
			//exibir_vetor(vet,tam);



		}
		mean = media(LACO,duration);
		fprintf(fp,"Heap_Sort,%.2fs\n",mean);
		break;
	}
	fclose(fp);
	free(vet);
	free(tempvet);
}


