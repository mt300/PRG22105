#include <stdlib.h>
#include <stdio.h>

#include "lista_enc.h"
#include "no.h"
#include "pilha.h"
#include "dados.h"

//#define DEBUG

#define FALSO 0
#define VERDADEIRO 1

struct pilhas {
	lista_enc_t *dados;
};


//cria uma pilha generica
pilha_t * cria_pilha (void)
{
    pilha_t * pilha =(pilha_t*)malloc(sizeof(pilha_t));
    
    pilha->dados = criar_lista_enc();

    return pilha;

}


//adiciona elemento
void push(void* dado, pilha_t *pilha)
{

		no_t *no = criar_no(dado);
		//printf("%s %d %c",obter_nome(obter_dado(no)),obter_idade(obter_dado(no)),obter_sexo(obter_dado(no)));
		add_cabeca(pilha->dados,no);

}

//retira elemento do topo
void *pop(pilha_t *pilha)
{
		no_t * no = obter_cabeca(pilha->dados);
		dado_t *dado = obter_dado(no);
		//printf("%s\n",obter_nome(obter_dado(obter_cabeca(pilha->dados))));

		remover_cabeca(pilha->dados);

		return dado;


}


void libera_pilha(pilha_t* pilha)
{

	while (lista_vazia(pilha->dados)!=0){
		pop(pilha);
	}
	free(pilha->dados);
	free(pilha);



}

int pilha_vazia(pilha_t *pilha)
{
    return lista_vazia(pilha->dados);
}
