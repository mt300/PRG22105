/** Programa que exibe na tela dados formatados
  * de um arquivo CSV conforme o padrão: 
  *         Series;Value;Time
  *         <int>;<float>;<string> 
  *         <int>;<float>;<string>
  */ 
  
#include <stdio.h>
#include "dados.h"
#include "fila.h"


int main(){
    fila_t *fila = ler_dados_csv_fila("velhinhos.csv");
     
    /* Imprima os dados:*/
    while (!fila_vazia(fila)){
      dado_t *meu_dado = dequeue(fila);

      printf( "%s %d %c\n",obter_nome(meu_dado),obter_idade(meu_dado),obter_sexo(meu_dado));
      liberar_dados(meu_dado);
    }

	libera_fila(fila);

    
    return 0;
}
