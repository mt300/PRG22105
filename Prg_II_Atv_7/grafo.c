/*
 * grafo.c
 *
 *  Created on: Nov 18, 2016
 *      Author: Renan Augusto Starke
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "grafo.h"
#include "fila.h"
#include "no.h"

struct vertices {
	int id;         /*!< Identificação numérica do vértice  */
	
	/*dados do BFS*/
	int distancia;
	vertice_t *pai;
    /* Mais informações, se necessário */
};

struct arestas {
	int adj;        /*!< Valor booleando. Verdadeiro representa uma adjacência entre dois vértices  */
	
    /* Mais informações, se necessário */
};

struct grafos{
	int n_vertices;        /*!< Número de vértices do grafo  */
	vertice_t *vertices;   /*!< Vetor de ponteiros: conjunto V */
	aresta_t **matriz_adj;	/* Matriz de adjacência: conjunto E */
};

/**
  * @brief  Cria uma novo grafo estático
  * @param	vertices: quantidade de vértices
  *
  * @retval grafo_t: ponteiro para um novo grafo
  */
grafo_t *cria_grafo(int vertices)
{
	int i;
	aresta_t **matriz_adj;
	/* Aloca estrutura do grafo */
    grafo_t *g = malloc(sizeof(grafo_t));

	if (g == NULL){
		perror("cria_grafo (g)");
		exit(EXIT_FAILURE);
	}

	/* Guarda número total de vértices */
	g->n_vertices = vertices;
    /* Aloca vértices */
	g->vertices = malloc(vertices * sizeof(vertice_t));

	if (g->vertices == NULL){
		perror("cria_grafo (vertices)");
		exit(EXIT_FAILURE);
	}

	/* Zera vetor de vértices */
	memset(g->vertices, 0, vertices * sizeof(vertice_t));
    
    
    /* Inicializa ID */
    for ( i = 0; i < vertices; i++ ){
        g->vertices[i].id = i;

    }    

    /* Aloca 1a dimensão da matriz de adjacência */
	matriz_adj = malloc(vertices * sizeof(aresta_t *));

	if (matriz_adj == NULL){
		perror("cria_grafo (matriz_adj)");
		exit(EXIT_FAILURE);
	}

	 /* Aloca 2a dimensão da matriz de adjacência */
	for ( i = 0; i < vertices; i++ )
	{
		matriz_adj[i] = calloc(vertices, sizeof(aresta_t));

		if (matriz_adj[i] == NULL){
			perror("cria_grafo (matriz_adj[i])");
			exit(EXIT_FAILURE);
		}
	}

	g->matriz_adj = matriz_adj;

	return g;
}

/**
  * @brief  Libera a memória utilizada pelo grafo
  * @param	Nenhum
  *
  * @retval Nenhum
  */
void libera_grafo (grafo_t *g){
	int i;

	if (g == NULL){
		perror("libera_grafo");
		exit(EXIT_FAILURE);
	}

	for (i=0; i < g->n_vertices; i++)
		free(g->matriz_adj[i]);

	free(g->matriz_adj);
	free(g->vertices);
	free(g);
}

/**
  * @brief  Cria adjacência entre vértices u e v
  * @param	u: índice do vértice u
  * @param  v: índice do vértice v
  *
  * @retval int: verdadeiro se adjacência for criada
  */
int cria_adjacencia(grafo_t *g, int u, int v){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices )
		return FALSE;

	g->matriz_adj[u][v].adj = TRUE;

	return TRUE;
}

/**
  * @brief  Remove adjacência entre vértices u e v
  * @param	u: índice do vértice u
  * @param  v: índice do vértice v
  *
  * @retval int: verdadeiro se adjacência for removida
  */
int rem_adjacencia(grafo_t *g, int u, int v){

	if (g == NULL){
		return FALSE;
	}

	if (u > g->n_vertices || v > g->n_vertices)
		return FALSE;

	g->matriz_adj[u][v].adj = FALSE;

	return TRUE;
}

/**
  * @brief  Retorna adjacência entre vértices u e v
  * @param	u: índice do vértice u
  * @param  v: índice do vértice v
  *
  * @retval int: verdadeiro se u for adjacente a v
  */
int adjacente(grafo_t *g, int u, int v){

	if (u > g->n_vertices || v > g->n_vertices)
		return FALSE;

	return ((g->matriz_adj[u][v].adj));
}

int tamanho_grafo_csv(char *arquivo){

	char texto[32];
	char c=',';
	int i,n=0;

	FILE *fp = fopen(arquivo,"r");

	if (!fp){
	        perror("ler_grafo_csv");
	        exit(-1);
	}

	fgets(texto,32,fp);

	for(i=0;i<strlen(texto);i++){
		if(texto[i]==c){
			n++;
		}


	}
	fclose(fp);
	return n;

}

void bfs(grafo_t *g, int fonte){

	int i;

	fila_t *fila = cria_fila();

	for (i=0;i<g->n_vertices;i++){
		g->vertices[i].distancia = -1;
		g->vertices[i].pai = NULL;
	}

	g->vertices[fonte].distancia = 0;
	//no_t *vertice_fonte = criar_no((int*)g->vertices[fonte].id);
	enqueue(&g->vertices[fonte],fila);

	while (!fila_vazia(fila)){
		vertice_t *u = dequeue(fila);

		int v;
		int id_u = u->id;

		for(v=0;v<g->n_vertices;v++){
			if(adjacente(g,id_u,v)){
				if(g->vertices[v].distancia == -1){
					g->vertices[v].distancia = u->distancia + 1;
					g->vertices[v].pai = u;
					//no_t *vertice_filho = criar_no((int*)g->vertices[v].id);
					enqueue(&g->vertices[v],fila);
				}
			}
		}
	}
	libera_fila(fila);
}

void print_bfs(grafo_t *g,int fonte){
	bfs(g,fonte);
	int i;
	for (i=0; i < g->n_vertices; i++){
		if(g->vertices[i].pai != NULL){


				printf("[%d] pai: %d  dist: %d\n", i,g->vertices[i].pai->id,g->vertices[i].distancia );

		}
		else{
				printf("[%d] pai: Nao tem  dist: %d\n", i,g->vertices[i].distancia );
		}
	}
}
