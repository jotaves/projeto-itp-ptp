/**
 *  \mainpage Processador de Imagens
 *  \author Bruno Felipe Moreira Lima
 *  \author João Victor Bezerra Barboza
 *  \date 2015
 *  \version 1.0
 *
 *  \file main.c
 *  \brief Arquivo principal
 *
 *  Arquivo que é compilado e executado.
 */

/** \brief Includes. */
#include <stdio.h> /** Biblioteca de funções de entrada/saída */
#include <string.h> /** Biblioteca de funções com strings */
#include <stdlib.h> /** Biblioteca de funções padrão */
#include <time.h> /** Biblioteca de funções para manipular data e hora */
#include "variaveis.h" /** Arquivo com todas as variáveis globais utilizadas no programa. */
#include "funcoes.h" /** Arquivo com todas as funções utilizadas no programa. */
#include "filtros.h" /** Arquivo com todos os filtros utilizados no programa. */

int main (void){
    /**
    *   \brief Função de agrupamento.
    *   Função para agrupar as outras funções e dar sequência ao programa.
    *   \return 0
    */
    entrada();
    RGB px[alt][lar];
    processamento(px);
	comandos(px);
	fclose(foto);
    return 0;
}
