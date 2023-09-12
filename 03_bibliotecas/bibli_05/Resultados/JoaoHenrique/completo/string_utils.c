#include <stdio.h>
#include "string_utils.h"
/**
 * @brief Retorna o tamanho de uma string.
 * @param str A string para obter o tamanho.
 * @return O tamanho da string.
 */
int string_length(char *str)
{
    char car;
    int i = 0;
    while(1)
    {
        car = str[i];
        if(car == '\0')
        {
            return i;
        }
        i++;
    }
}

/**
 * @brief Copia uma string de origem para destino.
 * @param src A string de origem.
 * @param dest A string de destino.
 */
void string_copy(char *src, char *dest)
{
    char car;
    int i = 0;
    while(1)
    {
        car = src[i];
        dest[i] = car;
        if(car == '\0')
        {
            return;
        }
        i++;
    }
}

/**
 * @brief Converte todos os caracteres de uma string para maiúsculas.
 * @param str A string para converter.
 */
void string_upper(char *str)
{
    int i = 0;
    while(1)
    {
        if(str[i] == '\0')
        {
            return;
        }
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] += ('A'-'a');
        }
        i++; 
    }
}

/**
 * @brief Converte todos os caracteres de uma string para minúsculas.
 * @param str A string para converter.
 */
void string_lower(char *str)
{
    int i = 0;
    while(1)
    {
        if(str[i] == '\0')
        {
            return;
        }
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += ('a'-'A');
        }
        i++; 
    }
}

/**
 * @brief Inverte uma string.
 * @param str A string para inverter.
 */
void string_reverse(char *str)
{
    int i = 0, j = 0;
    char car;
    while(1)
    {
        if(str[i] == '\0')
        {
            while(j < i)
            {
                car = str[i-1];
                str[i-1] = str[j];
                str[j] = car;
                i--;
                j++;
            }
            return;
        } 
        i++; 
    }
}