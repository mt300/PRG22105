#ifndef DADO_H_INCLUDED

/* Criação de tipo abstrato dado_t */
typedef struct dados dado_t;

/**
  * @brief  Cria um novo dado
  * @param  amostra: identificador da amostra
  * @param  temperatura: valor da temperatura
  * @param  timestamp: data e hora da amostra 
  *
  * @retval dado_t: ponteiro para uma novo dado
  */
dado_t * criar_dado (char  *nome, int idade, char sexo);


/* Outras funções aqui: fazer os comentários */

dado_t **ler_dados_csv(char *nome_do_arquivo, int *total_dados);


void liberar_dados(dado_t **vetor,int n);

char * obter_nome(dado_t *dado);
int  obter_idade(dado_t *dado);
char obter_sexo(dado_t *dado);


#endif
