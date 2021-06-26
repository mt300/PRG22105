/*
 * utils.h
 *
 *  Created on: 8 de abr de 2021
 *      Author: MATHEUS
 */


#ifndef UTILS_H_
#define UTILS_H_

/**
  * @brief  Exibe todos os valores de um vetor de inteiros
  * @param	vetor: refer�ncia de um vetor
  *         tam: tamanho do vetor
  *
  * @retval Nenhum
  */
void exibir_vetor(float *vetor, int tam);

/**
  * @brief  Completa com n�meros aleat�rios um vetor
  * @param	vetor: refer�ncia de um vetor
  *         tam: tamanho do vetor
  *
  * @retval Nenhum
  */
void completar_vetor(float *vetor, int tam);

float media(int tam,float *vet);

/**
  * @brief  Mede o tempo de uma ordena��o 20 vezes e faz a media guardando em um csv externo
  * @param	 tam: tamanho do vetor
  * 		op: op��o de ordena��o a ser medida (1:bubble_sort;2:Quick_sort;3:insert_sort;4:Binary_Insert_sort...)
  *
  *
  * @retval Nenhum
  */

void medir_tempo( int tam, int op);


#endif /* UTILS_H_ */

