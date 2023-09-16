#include <stdio.h>
#include "jogada.h"
#include "jogador.h"
#include "jogo.h"
#include "tabuleiro.h"

int main()
{
    tJogo jogo = CriaJogo();
    while (1)
    {
        ComecaJogo(jogo);
        if (!ContinuaJogo(jogo))
        {
            return 0;
        }
    }
}