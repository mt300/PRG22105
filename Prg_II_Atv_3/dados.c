
/* de um arquivo CSV conforme o padrão: 
  *         Series;Value;Time
  *         <int>;<float>;<string> 
  *         <int>;<float>;<string> */
  
/* Includes de sistema */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Includes do módulo */
#include "dados.h"
  
  
/* Ativa depuração do módulo, comente para código final */
#define DEBUG
  
  
struct dados {
	char nome[64];
	int idade;
	char sexo;
 
 
};


dado_t * criar_dado (char  *nome, int idade, char sexo){
    
    dado_t * meu_novo_dado = malloc(sizeof(struct dados));
    
    
    /* Novos dados são copiados para nova estrutura vinda do malloc */
    meu_novo_dado->idade = idade;
    meu_novo_dado->sexo = sexo;
    //use strncpy para o nome
    strcpy(meu_novo_dado->nome,nome);
    
    
    
    return meu_novo_dado;
}



dado_t **ler_dados_csv(char *nome_do_arquivo, int *total_dados){

	char info[128],sexo,nome[64];
	int i,idade,count = 0;

	FILE *fp = fopen(nome_do_arquivo,"r"); //abre arquivo


	fgets(info,128,fp); //pula uma linha


	while(fscanf(fp,"%63[^,],%d,%c",nome,&idade,&sexo)==3){
		count++;
	}

	*total_dados = count; // numero e linhas
	dado_t **dados_csv = malloc(sizeof(dado_t *)*count);

	rewind(fp);

	fgets(info,128,fp); //pula uma linha


	for(i=0;i<count;i++){
		fscanf(fp,"%63[^,],%d,%c",nome,&idade,&sexo);
		dados_csv[i] = criar_dado(nome,idade,sexo);
		//printf("%s\n",dados_csv[i]->nome);
	}


	fclose(fp);     //fecha arquivo
	return dados_csv;
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

void liberar_dados(dado_t **vetor,int n){

    int i=0;
    for(i=0;i<n;i++){
    
        free(vetor[i]);
    }
   free(vetor);
    
}
