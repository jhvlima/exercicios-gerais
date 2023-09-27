#include <stdio.h>
#include "eleicao.h"
#include "candidato.h"
#include "eleitor.h"


#define MAX_CANDIDATOS_POR_CARGO 3
#define MAX_ELEITORES 10


/**
 * @brief Inicializa uma eleição com valores padrão (zerando os votos invalidos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados.
 * @return Eleição inicializada.
 */
tEleicao InicializaEleicao()
{
    tEleicao eleicao;
    tCandidato candidato;
    int qntCandidatos, totalPresidentes = 0, totalGovernadores = 0, totalEleitores = 0;
    scanf("%d", &qntCandidatos);

    for (int i = 0; i < qntCandidatos; i++)
    {
        candidato = LeCandidato();
        if (ObtemCargo(candidato) == 'P')
        {
            CriaCandidato()
        }
        
    }
    eleicao.votosBrancosPresidente = 0;
    eleicao.votosNulosPresidente = 0;
    eleicao.votosBrancosGovernador = 0;
    eleicao.votosNulosGovernador = 0;

    return eleicao;
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada.
 * @return Eleição com os resultados da votação.
 */
tEleicao RealizaEleicao(tEleicao eleicao)
{

    return eleicao;
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao eleicao)
{

    //contador para o mior numero de votos
    ImprimeCandidato(candidato, porcentagem);




    printf("- NULOS E BRANCOS: %d, %d\n", nulos, brancos);
}