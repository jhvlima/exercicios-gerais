#include "matrix_utils.h"
#include <stdio.h>
/**
 * @brief Lê os valores da matriz especificada a partir da entrada padrão.
 * @param rows Número de linhas da matriz.
 * @param cols Número de colunas da matriz.
 * @param matrix Matriz a ser preenchida.
 */
void matrix_read(int rows, int cols, int matrix[rows][cols])
{
    int valor;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &valor);
            matrix[i][j] = valor;
        }
    }
}

/**
 * @brief Imprime a matriz especificada na saída padrão.
 * @param rows Número de linhas da matriz.
 * @param cols Número de colunas da matriz.
 * @param matrix Matriz a ser impressa.
 */
void matrix_print(int rows, int cols, int matrix[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (j == 0)
            {
                printf("|%d", matrix[i][j]);
            }
            else
            {
                printf(" %d", matrix[i][j]);
            }
        }
        printf("|\n");
    }
    printf("\n");
}

/**
 * @brief Verifica se é possível somar duas matrizes.
 * @param rows1 Número de linhas da primeira matriz.
 * @param cols1 Número de colunas da primeira matriz.
 * @param rows2 Número de linhas da segunda matriz.
 * @param cols2 Número de colunas da segunda matriz.
 * @return 1 se for possível somar as matrizes, 0 caso contrário.
 */
int possible_matrix_sum(int rows1, int cols1, int rows2, int cols2)
{
    if(rows1 == rows2 && cols1 == cols2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief Verifica se é possível subtrair duas matrizes.
 * @param rows1 Número de linhas da primeira matriz.
 * @param cols1 Número de colunas da primeira matriz.
 * @param rows2 Número de linhas da segunda matriz.
 * @param cols2 Número de colunas da segunda matriz.
 * @return 1 se for possível subtrair as matrizes, 0 caso contrário.
 */
int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2)
{
    if(rows1 == rows2 && cols1 == cols2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief Verifica se é possível multiplicar duas matrizes.
 * @param cols1 Número de colunas da primeira matriz.
 * @param rows2 Número de linhas da segunda matriz.
 * @return 1 se for possível multiplicar as matrizes, 0 caso contrário.
 */
int possible_matrix_multiply(int cols1, int rows2)
{
    if (rows2 == cols1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

/**
 * @brief Soma duas matrizes e armazena o resultado na primeira matriz.
 * @param rows1 Número de linhas da primeira matriz.
 * @param cols1 Número de colunas da primeira matriz.
 * @param matrix1 Primeira matriz.
 * @param rows2 Número de linhas da segunda matriz.
 * @param cols2 Número de colunas da segunda matriz.
 * @param matrix2 Segunda matriz.
 * @param result Matriz que armazenará o resultado da soma.
 */
void matrix_add(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1])
{
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
           result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

/**
 * @brief Subtrai duas matrizes e armazena o resultado na primeira matriz.
 * @param rows1 Número de linhas da primeira matriz.
 * @param cols1 Número de colunas da primeira matriz.
 * @param matrix1 Primeira matriz.
 * @param rows2 Número de linhas da segunda matriz.
 * @param cols2 Número de colunas da segunda matriz.
 * @param matrix2 Segunda matriz.
 * @param result Matriz que armazenará o resultado da subtração.
 */
void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1])
{
    for(int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

/**
 * @brief Multiplica duas matrizes e armazena o resultado na primeira matriz.
 * @param rows1 Número de linhas da primeira matriz.
 * @param cols1 Número de colunas da primeira matriz.
 * @param matrix1 Primeira matriz.
 * @param rows2 Número de linhas da segunda matriz.
 * @param cols2 Número de colunas da segunda matriz.
 * @param matrix2 Segunda matriz.
 * @param result Matriz que armazenará o resultado da multiplicação.
 */
void matrix_multiply(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2])
{
    int sum = 0;
    for(int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            sum = 0;
            for (int k = 0; k < rows2; k++)
            {
                sum += matrix1[i][k] * matrix2[k][j]; 
            }
            result[i][j] = sum;
        }
    }
}
/**
 * @brief Transpõe a matriz especificada.
 * @param rows Número de linhas da matriz.
 * @param cols Número de colunas da matriz.
 * @param matrix Matriz a ser transposta.
 * @param result Matriz que armazenará o resultado da transposição.
 */
void transpose_matrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix[j][i];
        }
    }
}

/**
 * @brief Multiplica a matriz especificada por um escalar.
 * @param rows Número de linhas da matriz.
 * @param cols Número de colunas da matriz.
 * @param matrix Matriz a ser multiplicada.
 * @param scalar Escalar a ser multiplicado.
 */
void scalar_multiply(int rows, int cols, int matrix[rows][cols], int scalar)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = matrix[i][j] * scalar;
        }
    }
}