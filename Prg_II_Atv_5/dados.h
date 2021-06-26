#ifndef DADO_H_INCLUDED

#include "pilha.h"

/* Criação de tipo abstrato dado_t */
typedef struct dados dado_t;



char *obter_nome(dado_t* dado);

int obter_idade(dado_t *dado);

char obter_sexo(dado_t *dado);

pilha_t *ler_dados_csv_pilha(char *nome_do_arquivo);

dado_t * criar_dado (char *nome, int idade, char sexo);

void liberar_dados(dado_t *dado);








#endif
