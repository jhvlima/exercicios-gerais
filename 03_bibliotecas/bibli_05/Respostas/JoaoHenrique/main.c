#include <stdio.h>
#include "string_utils.h"

int main()
{
    int acao;
    char string[1000];
    while(1)
    {
        printf("1 - Tamanho da string\n");
        printf("2 - Copiar string\n");
        printf("3 - Converter string para letras maiusculas\n");
        printf("4 - Converter string para letras minusculas\n");
        printf("5 - Imprimir string ao contrario\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida:\n"); 
        
        scanf("%s", string);
        scanf("%d", &acao);

        switch (acao)
        {
            case 1:
            {
                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                break;
            }
            case 5:
            {
                break;
            }
            case 6:
            {
                return 0;
            }

        }

    }
    





    return 0;
}