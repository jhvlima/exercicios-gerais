#include <stdio.h>
#include <stdlib.h>
#include "array.h"

struct Array
{
    int *vetor;
    int tam;
};


/**
 * @brief Inicializa um novo array, apontando data para NULL e tamanho para 0.
 * @return Ponteiro para a estrutura Array criada ou encerra caso não seja possível alocar memória.
 */
Array *CriarArray()
{
    Array *array = malloc(sizeof(Array));
    if (array  == NULL)
    {
        exit(1);
    }
    array->vetor = NULL;
    array->tam = 0;
    return array;
}


/**
 * @brief Libera a memória alocada para o array.
 * @param array Ponteiro para a estrutura Array a ser destruída.
 */
void DestruirArray(Array *array)
{
    if (array != NULL)
    {
        if (array->vetor != NULL)
        {
            free(array->vetor);
        }
        free(array);
    }
}

/**
 * @brief Lê os elementos do array a partir da entrada padrão e aloca memória para eles.
 * @details A leitura é feita até encontrar um ponto final (.) na entrada.
 * @param array Ponteiro para a estrutura Array a ser preenchida.
 */
void LerArray(Array *array)
{
    int element;
    while (scanf("%d", &element) != EOF && element != '.')
    {
        // Resize the array
        array->vetor = realloc(array->vetor, (array->tam + 1) * sizeof(int));

        // Check if realloc was successful
        if (array->vetor == NULL)
        {
            fprintf(stderr, "Failed to allocate memory for the array element\n");
            exit(EXIT_FAILURE);
        }

        // Store the scanned value
        array->vetor[array->tam] = element;
        array->tam++;
    }
}


int CompareInt(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}


/**
 * @brief Ordena os elementos do array em ordem crescente.
 * @param array Ponteiro para a estrutura Array a ser ordenada.
 */
void OrdenarArray(Array *array)
{
    qsort(array->vetor, array->tam, sizeof(int), CompareInt);
}


/**
 * @brief Realiza uma busca binária no array pelo elemento especificado.
 * @param array Ponteiro para a estrutura Array a ser buscada.
 * @param elementoBuscado Elemento a ser buscado no array.
 * @return Índice do elemento buscado no array, ou -1 caso não seja encontrado.
 */
int BuscaBinariaArray(Array *array, int elementoBuscado)
{
    OrdenarArray(array);

    int inicio = 0, fim = array->tam - 1; // Adjusted to work with valid indices
    int elemento_meio, comparacao;

    while (inicio < fim)
    {
        elemento_meio = (inicio + fim) / 2;
        comparacao = CompareInt(&elementoBuscado, &(array->vetor[elemento_meio]));

        if (comparacao == 0)
        {
            return elemento_meio;
        }
        if (comparacao < 0)
        {
            fim = elemento_meio - 1;
        }
        else
        {
            inicio = elemento_meio + 1;
        }
    }

    return -1;
}
