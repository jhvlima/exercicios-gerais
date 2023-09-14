#include <stdio.h>
#include "jogada.h"
#include "jogador.h"
#include "jogo.h"
#include "tabuleiro.h"

int main()
{
    tJogo jogo = CriaJogo();
    ComecaJogo(jogo);
    
    return 0;
}