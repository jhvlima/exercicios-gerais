#include "pessoa.h"

/**
 * @brief Cria uma nova pessoa e inicializa os ponteiros.
 * 
 * @return Uma nova pessoa e sem pais.
 */
tPessoa CriaPessoa()
{
    tPessoa pessoa;
    scanf("%[^\n]", pessoa.nome);
    pessoa.mae = 0;
    pessoa.pai = 0;
}

/**
 * @brief Lê os dados de uma pessoa.
 * 
 * @param pessoa Ponteiro para a pessoa a ser lida.
 */
void LePessoa(tPessoa *pessoa)
{
    
}

/**
 * @brief Imprime os dados de uma pessoa caso tenha pai e/ou mae associado(s).
 * 
 * @param pessoa Ponteiro para a pessoa a ser impressa.
 */
void ImprimePessoa(tPessoa *pessoa)
{
    int indicePai = pessoa->pai;
    printf("NOME COMPLETO: %s\n", pessoa->nome); 

    if (pessoa->pai != -1)
    {
        printf("PAI: %s\n", pessoa->nome); 
    }
    else
    {
        printf("NAO INFORMADO\n");
    }

    if (/* condition */)
    {
        /* code */
    }
    else
    {
        printf("NAO INFORMADO\n");
    }
    
}

/**
 * @brief Associa as famílias e grupos de pessoas.
 * Alem disso, e nessa funcao que sera lida a associacao entre as pessoas.
 * 
 * @param pessoas Ponteiro para a lista de pessoas a serem associadas.
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas);