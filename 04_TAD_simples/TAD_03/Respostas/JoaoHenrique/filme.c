#include <stdio.h>
#include "filme.h"
#include <string.h>
/**
 * @brief Cria um novo filme.
 * @param nome Nome do filme.
 * @param codigo Código do filme.
 * @param valor Valor do filme.
 * @param quantidade Quantidade em estoque do filme.
 * @return Filme criado.
 */
tFilme criarFilme (char* nome, int codigo, int valor, int quantidade)
{
    tFilme filme;
    strcpy(filme.nome, nome);
    filme.codigo = codigo;
    filme.valor = valor;
    filme.qtdEstoque = quantidade;
    filme.qtdAlugada = 0;
    return filme;
}

/**
 * @brief Lê um filme a partir da entrada padrão.
 * @return Filme lido.
 */
tFilme lerFilme ();

/**
 * @brief Obtém o código de um filme.
 * @param filme Filme a ser consultado.
 * @return Código do filme.
 */
int obterCodigoFilme (tFilme filme)
{
    return filme.codigo;
}

/**
 * @brief Imprime o nome de um filme.
 * @param filme Filme a ser impresso.
 */
void imprimirNomeFilme (tFilme filme)
{
    printf("%s", filme.nome);
}

/**
 * @brief Obtém o valor de um filme.
 * @param filme Filme a ser consultado.
 * @return Valor do filme.
 */
int obterValorFilme (tFilme filme)
{
    return filme.valor;
}

/**
 * @brief Obtém a quantidade em estoque de um filme.
 * @param filme Filme a ser consultado.
 * @return Quantidade em estoque do filme.
 */
int obterQtdEstoqueFilme (tFilme filme)
{
    return filme.qtdEstoque;
}

/**
 * @brief Obtém a quantidade alugada de um filme.
 * @param filme Filme a ser consultado.
 * @return Quantidade alugada do filme.
 */
int obterQtdAlugadaFilme (tFilme filme)
{
    return filme.qtdAlugada;
}

/**
 * @brief Verifica se um filme possui um determinado código.
 * @param filme Filme a ser consultado.
 * @param codigo Código a ser verificado.
 * @return 1 se o filme possui o código, 0 caso contrário.
 */
int ehMesmoCodigoFilme (tFilme filme, int codigo)
{
    if (filme.codigo == codigo)
    {
        return 1;
    }
    return 0;
}

/**
 * @brief Aluga um filme.
 * @param filme Filme a ser alugado.
 * @return Filme com a quantidade alugada atualizada.
 */
tFilme alugarFilme (tFilme filme)
{
    filme.qtdAlugada++;
    filme.qtdEstoque--;
    return filme;
}

/**
 * @brief Devolve um filme.
 * @param filme Filme a ser devolvido.
 * @return Filme com a quantidade alugada atualizada.
 */
tFilme devolverFilme (tFilme filme)
{
    filme.qtdAlugada--;
    filme.qtdEstoque++;
    return filme;
}

/**
 * @brief Compara os nomes de dois filmes.
 * @param filme1 Primeiro filme a ser comparado.
 * @param filme2 Segundo filme a ser comparado.
 * @return 0 se os nomes são iguais, um valor negativo se o nome do primeiro filme é menor que o do segundo, um valor positivo caso contrário.
 */
int compararNomesFilmes (tFilme filme1, tFilme filme2);
