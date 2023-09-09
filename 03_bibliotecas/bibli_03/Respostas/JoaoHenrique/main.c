#include <stdio.h>
#include "data.h"

int main()
{
    int dia1, mes1, ano1, dia2, mes2, ano2; 
    scanf("%d/%d/%d", &dia1, &mes1, &ano1);
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);
    
    if (!verificaDataValida(dia1, mes1, ano1) || !verificaDataValida(dia2, mes2, ano2))
    {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        return 0;
    }

    printf("Primeira data:");
    imprimeDataExtenso(dia1, mes1, ano1);
    printf("Segunda data:");
    imprimeDataExtenso(dia2, mes2, ano2);

    int comparacao = comparaData(dia1, mes1, ano1, dia2, mes2, ano2);

    if(!comparacao)
    {
        printf("As datas sao iguais\n");
    }
    else 
    {
        if(comparacao == 1)
        {
            printf("A segunda data eh mais antiga\n");
        }
        else
        {
           printf("A primeira data eh mais antiga\n");
        }
    }

    int diferenca = calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2);

    printf("A diferenca em dias entre as datas eh: ");
    printf("%d\n", diferenca);

    return 0;
}