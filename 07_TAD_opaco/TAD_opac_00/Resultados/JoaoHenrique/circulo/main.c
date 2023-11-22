#include <stdio.h>
#include "ponto.h"
#include "circulo.h"

int main ()
{
    float cx, cy, cr, px, py;
    scanf("%f %f %f %f %f", &cx, &cy, &cr, &px, &py);

    tCirculo circulo = Circulo_Cria(cx, cy, cr);
    tPonto ponto = Pto_Cria(px, py);

    int valor = Circulo_Interior(circulo, ponto);

    printf("%d", valor);

    Pto_Apaga(ponto);
    Circulo_Apaga(circulo);
    return 0;
}