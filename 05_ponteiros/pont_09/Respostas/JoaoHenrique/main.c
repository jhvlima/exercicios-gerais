#include <stdio.h>
#include "pessoa.h"

int main()
{
    int qtd_pessoas, qtd_associacao;
    scanf("%d", &qtd_pessoas);
    for (int  i = 0; i < qtd_pessoas; i++)
    {
        pessoa[i] = CriaPessoa();
    }
    scanf("%d", &qtd_associacao);
    for (int i = 0; i < qtd_associacao; i++)
    {
        pessoa[i] = LePessoa();
        AssociaFamiliasGruposPessoas(pessoa);
    }
    return 0;
}