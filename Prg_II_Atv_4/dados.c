#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"
#include "lista_enc.h"
#include "no.h"
  
struct dados {
   
   char nome[64];
   int idade;
   char sexo;
   
   
   
};


dado_t * criar_dado (char *nome, int idade, char sexo){
    
    dado_t * meu_novo_dado = malloc(sizeof(struct dados));
    
    
    strcpy(meu_novo_dado->nome,nome);
    meu_novo_dado->idade = idade;
    meu_novo_dado->sexo = sexo;

    
    
    return meu_novo_dado;
}



lista_enc_t *ler_dados_csv(char *nome_do_arquivo){
    char texto[64],nome[64];
    int idade;
    char sexo;
    /* Demais Variáveis */
    lista_enc_t *lista;
    dado_t *dado;
    no_t *meu_no;
    
    /* Veriáveis locais, conforme struct dados */
    
    
    FILE *fp = fopen(nome_do_arquivo,"r");
    
    if (!fp){
        perror("ler_dados_csv");
        exit(-1);
    }
    
    lista = criar_lista_enc();
    
    /* Ignora primeira linha */
    fgets(texto,64, fp);

    /* Note que não e mais necessário contar as linhas */


    while (fscanf(fp,"%63[^,],%d,%c\n",nome,&idade,&sexo)==3){


    	dado = criar_dado(nome,idade,sexo);
    	meu_no = criar_no(dado);
    	add_cauda(lista,meu_no);
    	//printf("%s\t%d\t%c\n",nome,idade,sexo);
        
        /* Cria um novo dado abstrato e armazena a sua referência */
        // dado = criar_dado(nome, idade, sexo);
        // meu_no = criar_no(dado);
        // add_cauda(lista, meu_no)

    }
    fclose(fp);
    return lista;
}

char *obter_nome(dado_t * dado){
	return dado->nome;

}

int obter_idade(dado_t *dado){
	return dado->idade;
}

char obter_sexo(dado_t *dado){
	return dado->sexo;
}
void liberar_dados(lista_enc_t *lista){

    no_t *no;
    no_t *prox;
    

    no = obter_cabeca(lista);
    while(no != NULL){

    	 free(obter_dado(no));
    	 prox = obter_proximo(no);
    	 free(no);
    	 no = prox;
    }
    free(lista);
    
    
}


