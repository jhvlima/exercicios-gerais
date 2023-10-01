#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main()
{
    int tamanho;
    scanf("%d", &tamanho);
    int numeros[tamanho];
    LeNumeros(numeros, tamanho);

    int maior, menor;
    float media;

    int *pmaior = &maior, *pmenor = &menor;
    float *pmedia = &media;

    EncontraMaiorMenorMedia(numeros, tamanho, pmaior, pmenor, pmedia); 
 
    printf("Maior elemento: %d\n", maior); 
    printf("Menor elemento: %d\n", menor); 
    printf("Media dos elementos: %.2f\n", media); 
 
    return 0;
}