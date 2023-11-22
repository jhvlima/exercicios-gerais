#include <stdio.h>
#include "aluno.h"

int main()
{
    int qnt_alunos;
    scanf("%d\n", &qnt_alunos);
    tAluno **aluno = malloc(qnt_alunos * sizeof(tAluno*));

    for (int i = 0; i < qnt_alunos; i++)
    {
        LeAluno(aluno[i]);
    }

    for (int i = 0; i < qnt_alunos; i++)
    {
        ApagaAluno(aluno[i]);
    }    
    return 0;
}