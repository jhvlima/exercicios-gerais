#include <stdio.h>
#include "eleicao.h"
#include "candidato.h"
#include "eleitor.h"

int main()
{
    tEleicao eleicao = InicializaEleicao();
    eleicao = RealizaEleicao(eleicao);
    ImprimeResultadoEleicao(eleicao);
    return 0;
}