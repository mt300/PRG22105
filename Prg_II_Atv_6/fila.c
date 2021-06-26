#include <stdlib.h>
#include <stdio.h>

#include "lista_enc.h"
#include "no.h"
#include "fila.h"



#define FALSO 0
#define VERDADEIRO 1

struct filas{
	lista_enc_t *dados;
};


//cria uma pilha generica
fila_t * cria_fila (void)
{
	fila_t *fila = (fila_t*)malloc(sizeof(fila_t));
	fila->dados = criar_lista_enc();
	return fila;

}


//adiciona elemento
void enqueue(void* dado, fila_t *fila)
{
	no_t *no = criar_no(dado);
	add_cauda(fila->dados,no);
	



}

//retira elemento do topo
void *dequeue(fila_t *fila)
{
	no_t *no = obter_cabeca(fila->dados);
	void *dado = obter_dado(no);
	
	remover_cabeca(fila->dados);

	return dado;


}


void libera_fila(fila_t* fila)
{
    if(lista_vazia(fila->dados)!=0){
    	fprintf(stderr,"Libera_fila com fila != 0");
    	exit(-1);
    }
    
    free(fila->dados);
    free(fila);


}

int fila_vazia(fila_t *fila)
{
    
	return !lista_vazia(fila->dados);
    
}
