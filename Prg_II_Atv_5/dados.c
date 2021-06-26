#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "dados.h"
  
struct dados {

	char nome[64];
	int idade;
	char sexo;

};


dado_t * criar_dado (char *nome, int idade, char sexo){
    
    dado_t * meu_novo_dado = malloc(sizeof(struct dados));
    
    
    // Colocar a criação dos dados aqui
    strcpy(meu_novo_dado->nome,nome);
    meu_novo_dado->idade = idade;
    meu_novo_dado->sexo = sexo;
    
    return meu_novo_dado;
}



pilha_t *ler_dados_csv_pilha(char *nome_do_arquivo){
    char texto[64],sexo,nome[64];
    int idade;
    pilha_t *pilha;
    dado_t *dado;
    
    /* Demais Variáveis conforme struct dados */
    
    
    
    FILE *fp = fopen(nome_do_arquivo,"r");
    
    if (!fp){
        perror("ler_dados_csv");
        exit(-1);
    }
    
    pilha = cria_pilha();
    
    /* Ignora primeira linha */
    fgets(texto,64, fp);

    /* Note que não e mais necessário contar as linhas */

    while ((fscanf(fp,"%63[^,],%d,%c",nome,&idade,&sexo))==3){
        dado = criar_dado(nome,idade,sexo);
        push(dado,pilha);

    	//printf("%s %d %c\n",dado->nome,dado->idade,dado->sexo);
        
        /* Cria um novo dado abstrato e armazena a sua referência */
        //dado = criar_dado(nome, idade, sexo);
        //push(dado,pilha);
        
     }
    fclose(fp);
    return pilha;
}



void liberar_dados(dado_t *dado){
    
    free(dado);
    
}

char *obter_nome(dado_t *dado){
	return dado->nome;
}

int obter_idade(dado_t *dado){
	return dado->idade;
}
char obter_sexo(dado_t *dado){
	return dado->sexo;
}
