#include <stdio.h>
#include<stdlib.h>
#include "jogo.h"
#include "jogador.h"
#include "tabuleiro.h"

struct Jogo
{
    tJogador *player_1;
    tJogador *player_2;
    tTabuleiro *tab;
};


/**
 * Aloca e retorna uma estrutura do tipo tJogo.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tJogo alocada.
 */
tJogo* CriaJogo()
{
    tJogo *jogo = malloc(sizeof(tJogo));
    jogo->tab = CriaTabuleiro();
    jogo->player_1 = CriaJogador(1);
    jogo->player_2 = CriaJogador(2);
    return jogo;
}


/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 * 
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo* jogo)
{
    
}


/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 * 
 * @param jogo o jogo atual.
 * 
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo* jogo)
{
    return !TemPosicaoLivreTabuleiro(jogo->tab);
}


/**
 * Verifica se o usuário deseja jogar novamente.
 * 
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo()
{
    char simounao = '\0';
    while (simounao != 's' && simounao != 'n')
    {
        printf("Jogar novamente? (s,n)\n");

        scanf("%*[^sn]");
        if (scanf("%c", &simounao) == EOF)
            simounao = 'n';
        scanf("%*[^\n]");
        if (scanf("%*c") == EOF)
            simounao = 'n';
    }
    if (simounao == 's')
        return 1;
    else
        return 0;
}


/**
 * Libera a memória de uma estrutura do tipo tJogo.
 * 
 * @param jogo a estrutura do tipo tJogo a ser liberada.
 */
void DestroiJogo(tJogo* jogo)
{
    DestroiJogador(jogo->player_1);
    DestroiJogador(jogo->player_2);
    DestroiTabuleiro(jogo->tab);
    free(jogo);
}