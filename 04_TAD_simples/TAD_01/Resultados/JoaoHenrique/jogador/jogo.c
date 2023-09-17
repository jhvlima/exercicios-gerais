#include <stdio.h>
#include "jogador.h"
#include "tabuleiro.h"
#include "jogo.h"

/**
 * Cria um jogo e retorna o jogo criado.
 * 
 * @return o jogo criado.
 */
tJogo CriaJogo()
{
    tJogo jogo;
    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo.jogador2 = CriaJogador(ID_JOGADOR_2);
    return jogo;
}


/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 * 
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo jogo)
{
    int jogador1Venceu = 0, jogador2Venceu = 0;
        while( 1 ){

            jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro); 
            jogador1Venceu = VenceuJogador(jogo.jogador1, jogo.tabuleiro);
            ImprimeTabuleiro(jogo.tabuleiro);

            if (jogador1Venceu || AcabouJogo(jogo))
                break;
            jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro); 
            jogador2Venceu = VenceuJogador(jogo.jogador2, jogo.tabuleiro);
            ImprimeTabuleiro(jogo.tabuleiro);
            
            if (jogador2Venceu || AcabouJogo(jogo))
                break;
        }

        if (jogador1Venceu)
            printf("JOGADOR 1 Venceu!\n");
        else if (jogador2Venceu)
            printf("JOGADOR 2 Venceu!\n");
        else 
            printf("Sem vencedor!\n");
}


/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 * 
 * @param jogo o jogo atual.
 * 
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo jogo)
{
    return !TemPosicaoLivreTabuleiro(jogo.tabuleiro);
}


/**
 * Verifica se o usuário deseja jogar novamente.
 * 
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo()
{
    printf("Jogar novamente? (s,n)\n");
    char car;
    while (1)
    {
        scanf("%*c");
        scanf("%c", &car);
        if (car == 's')
        {
            return 1;
        }
        if (car == 'n')
        {
            return 0;
        }
    }
}