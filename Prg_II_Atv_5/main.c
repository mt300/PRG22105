/** Programa que exibe na tela dados formatados
  * de um arquivo CSV conforme o padrão: 
  *         Series;Value;Time
  *         <int>;<float>;<string> 
  *         <int>;<float>;<string>
  */ 
  
#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include "pilha.h"


int main(){
    pilha_t *pilha = ler_dados_csv_pilha("velhinhos.csv");
     
    /* Imprima os dados:*/
    dado_t *meu_dado;
    while (pilha_vazia(pilha)!=0){

    	meu_dado = pop(pilha);

    	printf( "%s %d %c \n",obter_nome(meu_dado) ,obter_idade(meu_dado),obter_sexo(meu_dado));

    	liberar_dados(meu_dado);
    }

    libera_pilha(pilha);
    
    return 0;
}
