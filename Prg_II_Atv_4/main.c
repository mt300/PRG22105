/** Programa que exibe na tela dados formatados
  * de um arquivo CSV conforme o padrão: 
  *         Series;Value;Time
  *         <int>;<float>;<string> 
  *         <int>;<float>;<string>
  */ 
  
#include <stdio.h>
#include "dados.h"
#include "lista_enc.h"


int main(){
    lista_enc_t *lista = ler_dados_csv("velhinhos.csv");
    no_t * no = obter_cabeca(lista);

    while(no!=NULL){

    	printf("%s %d %c\n",obter_nome(obter_dado(no)),obter_idade(obter_dado(no)),obter_sexo(obter_dado(no)));

    	no = obter_proximo(no);
    }
    liberar_dados(lista);
    
    return 0;
}
