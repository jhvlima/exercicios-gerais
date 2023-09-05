#include <stdio.h>
#include "matrix_utils.h"

int main()
{
    int linha1, coluna1, linha2, coluna2, linhaResult, colunaResult;

    scanf("%d %d", &linha1, &coluna1);
    int matriz1[linha1][coluna1];
    matrix_read(linha1, coluna1, matriz1);
    
    scanf("%d %d", &linha2, &coluna2);
    int matriz2[linha2][coluna2];
    matrix_read(linha2, coluna2, matriz2);

    printf("1 - Somar matrizes\n
            2 - Subtrair matrizes\n
            3 - Multiplicar matrizes\n
            4 - Multiplicacao de uma matriz por escalar\n
            5 - Transposta de uma matriz\n
            6 - Encerrar o programa\n
            Opcao escolhida:\n");

    while(1)
    {
        scanf("%d", &acao);
        switch (acao)
        {
            case 1:
            {
                if(possible_matrix_sum(linha1, coluna1, linha2, coluna2))
                {
                    matrix_add(linha1, coluna1, matriz1, linha2, coluna2, matriz2, resultado);
                }
                break;
            }
            case 2:
            {
                if(possible_matrix_sub(linha1, coluna1, linha2, coluna2))
                {
                    matrix_sub(linha1, coluna1, matriz1, linha2, coluna2, matriz2, resultado);
                }
                break;
            }
            case 3:
            {
                if(possible_matrix_multiply(coluna1, linha2))
                {
                    matrix_multiply(linha1, coluna1, matriz1, linha2, coluna2, matriz2, resultado);
                }
                break;
            }
            case 4:
            {
                int escalar = 0;
                scanf("%d", &escalar);
                matrix_add(linha1, coluna1, matriz1, escalar);
                break;
            }
            case 5:
            {
                transpose_matrix(linha1, coluna1, matriz1, resultado);
            }
            case 6:
            {
                return 0;
            }
        }
    }

    
    return 0;
}