#include <stdio.h>
#include "matrix_utils.h"

int main()
{
    int linha1, coluna1, linha2, coluna2;

    scanf("%d %d", &linha1, &coluna1);
    int matriz1[linha1][coluna1];
    matrix_read(linha1, coluna1, matriz1);
    
    scanf("%d %d", &linha2, &coluna2);
    int matriz2[linha2][coluna2];
    matrix_read(linha2, coluna2, matriz2);

    while(1)
    {
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida:\n");
        int acao;
        scanf("%d", &acao);
        switch (acao)
        {
            case 1:
            {
                int resultado[linha1][coluna1];
                if(possible_matrix_sum(linha1, coluna1, linha2, coluna2))
                {
                    matrix_add(linha1, coluna1, matriz1, linha2, coluna2, matriz2, resultado);
                    matrix_print(linha2, coluna1, resultado);
                }
                else
                {
                    printf("Error: as dimensoes da matriz nao correspondem\n");
                    printf("\n");
                }
                break;
            }
            case 2:
            {
                if(possible_matrix_sub(linha1, coluna1, linha2, coluna2))
                {
                    int resultado[linha1][coluna1];
                    matrix_sub(linha1, coluna1, matriz1, linha2, coluna2, matriz2, resultado);
                    matrix_print(linha1, coluna1, resultado);
                }
                else
                {
                    printf("Error: as dimensoes da matriz nao correspondem\n");
                    printf("\n");
                }
                break;
            }
            case 3:
            {
                if(possible_matrix_multiply(coluna1, linha2))
                {
                    int resultado[linha2][coluna1];
                    matrix_multiply(linha1, coluna1, matriz1, linha2, coluna2, matriz2, resultado);
                    matrix_print(linha1, coluna2, resultado);
                }
                else
                {
                    printf("Error: as dimensoes da matriz nao correspondem\n");
                    printf("\n");
                }
                break;
            }
            case 4:
            {
                int escalar = 0, matriz = 0;
                scanf("%d %d", &escalar, &matriz);
                if (matriz == 1)
                {
                    scalar_multiply(linha1, coluna1, matriz1, escalar);
                    matrix_print(linha1, coluna1, matriz1);
                }
                else if (matriz == 2)
                {
                    scalar_multiply(linha2, coluna2, matriz2, escalar);
                    matrix_print(linha2, coluna2, matriz2);
                }
                else
                {
                    printf("Erro: Escolha da matriz invalida\n");
                    printf("\n");
                }
                break;
            }
            case 5:
            {   
                int matriz = 0;
                scanf("%d", &matriz);
                if (matriz == 1)
                {
                    int resultado[linha1][coluna1];
                    transpose_matrix(linha1, coluna1, matriz1, resultado);
                    matrix_print(linha1, coluna1, resultado);
                }
                else if (matriz == 2)
                {
                    int resultado[linha2][coluna2];
                    transpose_matrix(linha2, coluna2, matriz2, resultado);
                    matrix_print(linha2, coluna2, resultado);
                }
                else
                {
                    printf("Erro: Escolha da matriz invalida\n");
                    printf("\n");
                }
                break;
            }
            case 6:
            {
                return 0;
            }
        }
    }
}