#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "fila.h"
#include "dados.h"
  
struct dados {
	char nome[64],sexo;
	int idade;
};


dado_t * criar_dado (char *nome, int idade, char sexo){
    
    dado_t * meu_novo_dado = malloc(sizeof(struct dados));
    
    
    // Colocar a criação dos dados aqui
    strcpy(meu_novo_dado->nome,nome);
    meu_novo_dado->idade = idade;
    meu_novo_dado->sexo = sexo;
    
    return meu_novo_dado;
}



fila_t *ler_dados_csv_fila(char *nome_do_arquivo){
    char texto[64],nome[64],sexo;
    int idade;
    fila_t *fila;
    dado_t *dado;
    
    /* Demais Variáveis conforme struct dados */
    
    
    
    FILE *fp = fopen(nome_do_arquivo,"r");
    
    if (!fp){
        perror("ler_dados_csv");
        exit(-1);
    }
    
    fila = cria_fila();
    
    /* Ignora primeira linha */
    fgets(texto,64, fp);

    /* Note que não e mais necessário contar as linhas */


    while (fscanf(fp,"%63[^,],%d,%c",nome,&idade,&sexo)==3){

    	dado = criar_dado(nome,idade,sexo);
        enqueue(dado,fila);
        /* Cria um novo dado abstrato e armazena a sua referência */
        // dado = criar_dado(nome, idade, sexo);
        //enqueue(dado,fila);
        
    }
    fclose(fp);
    return fila;
}



void liberar_dados(dado_t *dado){
    
	free(dado);
    
    
}

char *obter_nome(dado_t *dado){
	return dado->nome;
}

char obter_sexo(dado_t *dado){
	return dado->sexo;
}
int obter_idade(dado_t *dado){
	return dado->idade;
}
