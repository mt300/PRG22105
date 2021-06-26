/*
 * utils.c
 *
 *  Created on: 8 de abr de 2021
 *      Author: MATHEUS
 */



#include <stdio.h>
#include <stdlib.h>


void exibir_vetor(int *vetor, int tam){

	int i;

	for (i=0; i < tam; i++)
		printf("[%d] \t %d\n", i, vetor[i]);

	puts("---------------------------");

}

void completar_vetor(int *vetor, int tam){

	int i;

	for (i=0; i < tam; i++)
		vetor[i] = random();
}
