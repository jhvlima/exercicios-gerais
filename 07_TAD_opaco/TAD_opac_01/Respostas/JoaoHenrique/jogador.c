#include <stdio.h>
#include<stdlib.h>
#include <tabuleiro.h>
#include "jogador.h"

#define ID_JOGADOR_1 1
#define ID_JOGADOR_2 2

struct Jogador
{
    int id;

};


/**
 * Aloca e retorna uma estrutura do tipo tJogador.
 * Se a alocação falhar, o programa é encerrado.
 *
 *  @param idJogador o ID do jogador (1 ou 2).
 * 
 * @return a estrutura do tipo tJogador alocada.
 */
tJogador* CriaJogador(int idJogador)
{
    tJogador *jogador = malloc(sizeof(tJogador));
    if (jogador == NULL)
    {
        exit(1);
    }
    jogador->id = idJogador;
    return jogador
}


/**
 * Libera a memória de uma estrutura do tipo tJogador.
 * 
 * @param jogador a estrutura do tipo tJogador a ser liberada.
 */
void DestroiJogador(tJogador* jogador)
{
    free(jogador);
}


/**
 * Lê uma jogada e armazena em uma estrutura do tipo tJogada.
 * 
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 */
void JogaJogador(tJogador* jogador, tTabuleiro* tabuleiro)
{
    
}


/**
 * Verifica se o jogador venceu o jogo.
 * 
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador* jogador, tTabuleiro* tabuleiro)
{
    
}