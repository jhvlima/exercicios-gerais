#include <stdio.h>
#include "utils.h"

/**
 * @brief Lê uma sequência de inteiros da entrada padrão e os armazena em um array.
 * @param array Ponteiro para o array onde os inteiros serão armazenados.
 * @param tamanho O tamanho do array.
 */
void LeNumeros(int *array, int tamanho)
{
    int valor;
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &valor);
        array[i] = valor;
    }
}

/**
 * @brief Encontra o maior, o menor e a média dos valores em um array de inteiros.
 * @param array Ponteiro para o array de inteiros.
 * @param tamanho O tamanho do array.
 * @param maior Ponteiro para a variável que armazenará o maior valor.
 * @param menor Ponteiro para a variável que armazenará o menor valor.
 * @param media Ponteiro para a variável que armazenará a média dos valores.
 */
void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media)
{
    int i;
    float total = 0;
    for (i = 0; i < tamanho; i++)
    {
        if (i == 0)
        {
            *maior = array[i];
            *menor = array[i];
        }
        
        if (*maior < array[i])
        {
            *maior = array[i];
        }
        if (*menor > array[i])
        {
            *menor = array[i];
        }
        total+= array[i];
    }
    *media = total/i;
}