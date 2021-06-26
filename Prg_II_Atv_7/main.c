/*
 ============================================================================
 Name        : grafos-adj-matrix.c
 Author      : Renan Augusto Starke
 Version     :
 Copyright   : Renan, todo os direitos reservados
 Description : grafos com matriz de adjacencia, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"
#include "fila.h"

int main(void) {


	int i,j,k,m[5],ma[5][5];
	char texto[32],c;
	grafo_t *g;


    /* Cria grafo com 20 vértices */


	k = tamanho_grafo_csv("grafo.csv");
	g = cria_grafo(k);

	/*    Adicionar arestas    */
	FILE *fp = fopen("grafo.csv","r");
	fgets(texto,32,fp);

	for(i=0;i<k;i++){
		fscanf(fp,"%c,%d,%d,%d,%d,%d\n",&c,&m[0],&m[1],&m[2],&m[3],&m[4]);
		printf("\t%c",c);
		for(j=0;j<k;j++){
			ma[i][j] = m[j];
		}
	}
	fclose(fp);

	for(i=0;i<k;i++){
		for(j=0;j<k;j++){
			if(ma[i][j]==1){
				cria_adjacencia(g,i,j);
			}
		}

	}
	/***************************/


	/* Imprime matriz */

	printf("\n\n");
	for (i=0; i<k;i++){
		switch (i){
			case 0: printf("A\t");
					break;
			case 1: printf("B\t");
					break;
			case 2: printf("C\t");
					break;
			case 3: printf("D\t");
					break;
			case 4: printf("E\t");
					break;
			}
		for(j=0;j<k;j++){
			printf("%d\t",adjacente(g,i,j));
		}
		printf("\n\n");
	}


	print_bfs(g,0);



	libera_grafo(g);

	return EXIT_SUCCESS;
}
