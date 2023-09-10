#include <stdio.h>
#include "data.h"
/**
 * @brief Verifica se uma data é válida.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 * @return int Retorna 1 se a data é válida e 0 caso contrário.
 */
int verificaDataValida(int dia, int mes, int ano)
{
    if (dia <= 0 || mes <= 0 || ano < 0 || dia >= 32 || mes >= 13)
    {
        return 0;
    }
    if((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 1 || mes == 10 || mes == 12) && (dia <= 31))
    {
        return 1;
    }
    if((mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia <= 30))
    {
        return 1;
    }
    if(mes == 2)
    {
        if ((verificaBissexto(ano)) && (dia <= 29))
        {
            return 1;
        }
        if (dia <= 28)
        {
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Imprime o nome do mês por extenso.
 * 
 * @param mes Mês a ser impresso.
 */
void imprimeMesExtenso(int mes)
{
    switch (mes)
    {
        case 1:
        {
            printf("Janeiro");
            break;
        }
        case 2:
        {
            printf("Fevereiro");
            break;
        }
        case 3:
        {
            printf("Marco");
            break;
        }
        case 4:
        {
            printf("Abril");
            break;
        }
        case 5:
        {
            printf("Maio");
            break;
        }
        case 6:
        {
            printf("Junho");
            break;
        }
        case 7:
        {
            printf("Julho");
            break;
        }
        case 8:
        {
            printf("Agosto");
            break;
        }
        case 9:
        {
            printf("Setembro");
            break;
        }
        case 10:
        {
            printf("Outubro");
            break;
        }
        case 11:
        {
            printf("Novembro");
            break;
        }
        case 12:
        {
            printf("Dezembro");
            break;
        }
    }
}

/**
 * @brief Imprime a data por extenso.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeDataExtenso(int dia, int mes, int ano)
{
    printf("%d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %d\n", ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param ano Ano a ser verificado.
 * @return int Retorna 1 se o ano é bissexto e 0 caso contrário.
 */
int verificaBissexto(int ano)
{
    if (!(ano % 400))
    {
        return 1;
    }
    if (!(ano % 100))
    {
        return 0;
    }
    if (!(ano % 4))
    {
        return 1;
    }
    return 0;   
}

/**
 * @brief Calcula o número de dias de um mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias do mês.
 */
int numeroDiasMes(int mes, int ano)
{
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 1 || mes == 10 || mes == 12)
    {
        return 31;
    }
    if(mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        return 30;
    }
    if (mes == 2)
    {
        if (verificaBissexto(ano))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
    else
    {
        printf("Erro: mes invalido");
        return 0;
    }
}

/**
 * @brief Compara duas datas.
 * 
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return int Retorna 1 se a primeira data é maior que a segunda, -1 se a primeira data é menor que a segunda
 * e 0 se as datas são iguais.
 */
int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    if (ano1 > ano2 || ((ano1 == ano2) && (mes1 > mes2)) || ((ano1 == ano2) && (mes1 == mes2) && (dia1 > dia2)))
    {
        return -1;
    }
    if (ano1 < ano2 || ((ano1 == ano2) && (mes1 < mes2)) || ((ano1 == ano2) && (mes1 == mes2) && (dia1 < dia2)))
    {
        return 1;
    }
    return 0;
}

/**
 * @brief Calcula o número de dias até o mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias até o mês.
*/
int calculaDiasAteMes(int mes, int ano)
{
    int resultado = 0;
    
    for (int i = 1; i <= mes; i++)
    {
        resultado += numeroDiasMes(i, ano);
    }
    return resultado;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return int Retorna o número de dias de diferença entre as datas.
 */
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    int soma = 0;
    if(ano1 > ano2)
    {
        for (int i = ano2; i < ano1; i++)
        {
            soma += 365;
            if (verificaBissexto(i))
            {
                soma++;
            }
        }
        soma += calculaDiasAteMes(mes1, ano1);
        soma += dia1;
        soma -= calculaDiasAteMes(mes2, ano2);
        soma -= numeroDiasMes(mes2, ano1) - dia2;
    }
    else if (ano1 < ano2)
    {
        for (int i = ano1; i < ano2; i++)
        {
            soma += 365;
            if (verificaBissexto(i))
            {
                soma++;
            }
        }
        soma += calculaDiasAteMes(mes2, ano2);
        soma += dia2;
        soma -= calculaDiasAteMes(mes1, ano1);
        soma -= numeroDiasMes(mes1, ano2) - dia1;
    }
   
    if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == -1)
    {
        for (int i = mes1; i < mes2; i++)
        {
            soma += numeroDiasMes(i, ano1);
        }
        soma += dia2 - dia1;
    }
    else if(comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 1)
    {
        for (int i = mes2; i < mes1; i++)
        {
            soma += numeroDiasMes(i, ano1);
        }
        soma += dia1 - dia2;
    }

    return soma;
}