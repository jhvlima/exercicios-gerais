#include <stdio.h>
#include "string_utils.h"

int main()
{
    int acao;
    char string[1000];
    scanf("%[^\n]", string);
    while(1)
    {
        printf("1 - Tamanho da string\n");
        printf("2 - Copiar string\n");
        printf("3 - Converter string para letras maiusculas\n");
        printf("4 - Converter string para letras minusculas\n");
        printf("5 - Imprimir string ao contrario\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida:\n"); 
        
        scanf("%d", &acao);

        switch (acao)
        {
            case 1:
            {
                printf("Tamanho da string: %d\n", string_length(string));
                printf("\n");
                break;
            }
            case 2:
            {
                char copy[1000];
                string_copy(string, copy);
                printf("String copiada: %s\n", copy);
                printf("\n");
                break;
            }
            case 3:
            {
                string_upper(string);
                printf("String convertida para maiusculas: %s\n", string);
                printf("\n");
                break;
            }
            case 4:
            {
                string_lower(string);
                printf("String convertida para minusculas: %s\n", string);
                printf("\n");
                break;
            }
            case 5:
            {
                string_reverse(string);
                printf("String invertida: %s\n", string);
                printf("\n");
                break;
            }
            case 6:
            {
                return 0;
            }
        }
    }
}