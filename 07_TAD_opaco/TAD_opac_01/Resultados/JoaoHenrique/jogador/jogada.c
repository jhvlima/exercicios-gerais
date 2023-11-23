#include <stdlib.h>
#include <stdio.h>
#include "jogada.h"

struct Jogada
{
    int sucesso;
    int coord_x;
    int coord_y;
};

/**
 * Aloca e retorna uma estrutura do tipo tJogada.
 * Se a alocação falhar, o programa é encerrado.
 *
 * @return a estrutura do tipo tJogada alocada.
 */
tJogada *CriaJogada()
{
    tJogada *jogada = malloc(sizeof(tJogada));
    jogada->sucesso = 0;

    if (jogada == NULL)
    {
        exit(1);
    }

    return jogada;
}

/**
 * Libera a memória de uma estrutura do tipo tJogada.
 *
 * @param jogada a estrutura do tipo tJogada a ser liberada.
 */
void DestroiJogada(tJogada *jogada)
{
    free(jogada);
}

/**
 * Lê uma jogada e armazena em uma estrutura do tipo tJogada.
 *
 * @param jogada a estrutura do tipo tJogada a ser preenchida.
 */
void LeJogada(tJogada *jogada)
{
    printf("Digite uma posicao (x e y):\n");
    jogada->sucesso = 1;

    if (scanf("%d %d", &jogada->coord_x, &jogada->coord_y) != 2)
    {
        jogada->sucesso = 0;
    }
}

/**
 * Retorna a coordenada X da jogada.
 *
 * @param jogada a estrutura do tipo tJogada.
 *
 * @return a coordenada X da jogada.
 */
int ObtemJogadaX(tJogada *jogada)
{
    return jogada->coord_x;
}

/**
 * Retorna a coordenada Y da jogada.
 *
 * @param jogada a estrutura do tipo tJogada.
 *
 * @return a coordenada Y da jogada.
 */
int ObtemJogadaY(tJogada *jogada)
{
    return jogada->coord_y;
}

/**
 * Retorna 1 se a jogada foi bem sucedida e 0 caso contrário.
 *
 * @param jogada a estrutura do tipo tJogada.
 *
 * @return 1 se a jogada foi bem sucedida, 0 caso contrário.
 */
int FoiJogadaBemSucedida(tJogada *jogada)
{
    if (jogada->sucesso)
    {
        return 1;
    }
    return 0;
}
