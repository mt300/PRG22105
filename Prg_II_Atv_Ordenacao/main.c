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
#include "quick_sort.h"

/* Tamanho do vetor */
#define TAM_VETOR 100000


int main(void) {
	srand(getpid()^time(NULL));

	int i;

	for(i=1;i<=7;i++){
		medir_tempo(TAM_VETOR,i);
		printf("Medi��o (%d/7) concluida\n",i);
	}


	return EXIT_SUCCESS;
}
