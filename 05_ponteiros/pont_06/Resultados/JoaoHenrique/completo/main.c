#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main()
{
    tData data;
    tData dataIni;
    tData dataFim;

    tData *pdata = &data;
    tData *pdataFim = &dataFim;

    LeData(&dataIni);
    LeData(&dataFim);

    data = dataIni;
    while (!EhIgual(pdata, pdataFim))
    {
        ImprimeData(pdata);
        printf("\n");

        AvancaParaDiaSeguinte(&data);
    }

    return 0;
}