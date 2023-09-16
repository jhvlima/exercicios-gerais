#include <stdio.h>
#include "jogador.h"
#include "tabuleiro.h"
#include "jogada.h"


/**
 * Cria um jogador com o id passado como parâmetro e retorna o jogador criado.
 * 
 * @param idJogador o id do jogador (1 ou 2).
 * 
 * @return tJogador o jogador criado.
 */
tJogador CriaJogador(int idJogador)
{
    tJogador jogador;
    jogador.id = idJogador;
    return jogador;
}

/**
 * Recebe um jogador e um tabuleiro e retorna o tabuleiro com a jogada do jogador.
 * 
 * @param jogador o jogador que fará a jogada.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return o tabuleiro atualizado com a jogada do jogador.
 */
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    
    tJogada jogada = LeJogada();
    
    if(!FoiJogadaBemSucedida(jogada))
    {
        printf("Formato invalido!\n");
        return tabuleiro;
    }

    int x = ObtemJogadaX(jogada);
    int y = ObtemJogadaY(jogada);

    if (!EhPosicaoValidaTabuleiro(x, y))
    {
        printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x, y);
        return tabuleiro;
    }

    if (!EstaLivrePosicaoTabuleiro(tabuleiro, x, y))
    {
        printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
        return tabuleiro;
    }

    int peca = PECA_1;

    if (jogador.id == ID_JOGADOR_2)
    {
        peca = PECA_2;
    }

    tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, peca, x, y);

    return tabuleiro;
}


/**
 * Recebe um jogador e um tabuleiro e retorna 1 se o jogador venceu e 0 caso contrário.
 * 
 * @param jogador o jogador a ser verificado.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    int peca = (jogador.id == ID_JOGADOR_1 ? PECA_1: PECA_2);
        {
            if (    EstaMarcadaPosicaoPecaTabuleiro( tabuleiro, 0, 0, peca ) &&
                    EstaMarcadaPosicaoPecaTabuleiro( tabuleiro, 0, 1, peca ) &&
                    EstaMarcadaPosicaoPecaTabuleiro( tabuleiro, 0, 2, peca ) )
            {
                return 1;
            }
            if (    EstaMarcadaPosicaoPecaTabuleiro( tabuleiro, 1, 0, peca ) &&
                    EstaMarcadaPosicaoPecaTabuleiro( tabuleiro, 1, 1, peca ) &&
                    EstaMarcadaPosicaoPecaTabuleiro( tabuleiro, 1, 2, peca ) )
            {
                return 1;
            }
            if (    EstaMarcadaPosicaoPecaTabuleiro( tabuleiro, 2, 0, peca ) &&
                    EstaMarcadaPosicaoPecaTabuleiro( tabuleiro, 2, 1, peca ) &&
                    EstaMarcadaPosicaoPecaTabuleiro( tabuleiro, 2, 2, peca ) )
            {   
                return 1;
            }
            if (    EstaMarcadaPosicaoPecaTabuleiro( tabuleiro, 0, 0, peca ) &&
                    EstaMarcadaPosicaoPecaTabuleiro( tabuleiro, 1, 0, peca ) &&
                    EstaMarcadaPosicaoPecaTabuleiro( tabuleiro, 2, 0, peca ) )
            {
                return 1;
            }
            if (    EstaMarcadaPosicaoPecaTabuleiro( tabuleiro, 0, 1, peca ) &&
                    EstaMarcadaPosicaoPecaTabuleiro( tabuleiro, 1, 1, peca ) &&
                    EstaMarcadaPosicaoPecaTabuleiro( tabuleiro, 2, 1, peca ) )
            {
                return 1;
            }
            if (    EstaMarcadaPosicaoPecaTabuleiro( tabuleiro, 0, 2, peca ) &&
                    EstaMarcadaPosicaoPecaTabuleiro( tabuleiro, 1, 2, peca ) &&
                    EstaMarcadaPosicaoPecaTabuleiro( tabuleiro, 2, 2, peca ) )
            {
                return 1;
            }
            if (    EstaMarcadaPosicaoPecaTabuleiro( tabuleiro, 0, 0, peca ) &&
                    EstaMarcadaPosicaoPecaTabuleiro( tabuleiro, 1, 1, peca ) &&
                    EstaMarcadaPosicaoPecaTabuleiro( tabuleiro, 2, 2, peca ) )
            {
                return 1;
            }
            if (    EstaMarcadaPosicaoPecaTabuleiro( tabuleiro, 0, 2, peca ) &&
                    EstaMarcadaPosicaoPecaTabuleiro( tabuleiro, 1, 1, peca ) &&
                    EstaMarcadaPosicaoPecaTabuleiro( tabuleiro, 2, 0, peca ) )
            {
                return 1;
            }
        return 0;
    }
}