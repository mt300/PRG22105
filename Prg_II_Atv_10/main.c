/*
 * main.c
 *
 *  Created on: 8 de abr de 2021
 *      Author: MATHEUS
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

/* Fun��es auxiliares */
#include "utils.h"

/* Include das ordenca��es */
#include "bubble_sort.h"

/* Tamanho do vetor */
#define TAM_VETOR 10


int main(void) {

	int *vet;

	/* Muda a smenete do gerador de n�mero aleat�rios */
	srand(getpid()^time(NULL));

	/* Aloca mem�ria do vetor */
	vet = (int *)malloc(sizeof(int) * TAM_VETOR);

	/* Preenche vetor com numeros aleat�rios */
	completar_vetor(vet, TAM_VETOR);

	/* Exibe dados */
	exibir_vetor(vet,TAM_VETOR);

	/* Ordena */
	bubble_sort(vet, TAM_VETOR);

	/* Exibe dados */
	exibir_vetor(vet,TAM_VETOR);

	free(vet);

	return EXIT_SUCCESS;
}
