#ifndef DADO_H_INCLUDED
#define DADO_H_INCLUDED

#include "fila.h"
#include "lista_enc.h"

/* Criação de tipo abstrato dado_t */
typedef struct dados dado_t;




dado_t * criar_dado (char *nome, int idade, char sexo);

fila_t *ler_dados_csv_fila(char *nome_do_arquivo);

void liberar_dados(dado_t *dado);

char *obter_nome(dado_t *dado);

char obter_sexo(dado_t *dado);

int obter_idade(dado_t *dado);


#endif
