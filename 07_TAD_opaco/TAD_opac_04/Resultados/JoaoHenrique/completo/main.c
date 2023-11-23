#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

// Comparison function for qsort
int CompareAlunos(const void *a, const void *b)
{
    tAluno *aluno1 = *(tAluno **)a;
    tAluno *aluno2 = *(tAluno **)b;

    // Compare based on matricula
    return ComparaMatricula(aluno1, aluno2);
}


void OrdenaLista(tAluno **aluno, int qnt_alunos)
{
    qsort(aluno, qnt_alunos, sizeof(tAluno *), CompareAlunos);
}

void ImprimeLista(tAluno **aluno, int qnt_alunos)
{
    OrdenaLista(aluno, qnt_alunos);

    for (int i = 0; i < qnt_alunos; i++)
    {
        if (VerificaAprovacao(aluno[i]))
        {
            ImprimeAluno(aluno[i]);
        }
    }
}


int main()
{
    int qnt_alunos;
    scanf("%d\n", &qnt_alunos);
    tAluno **aluno = malloc(qnt_alunos * sizeof(tAluno*));

    for (int i = 0; i < qnt_alunos; i++)
    {
        aluno[i] = CriaAluno();
        LeAluno(aluno[i]);
    }

    ImprimeLista(aluno, qnt_alunos);

    for (int i = 0; i < qnt_alunos; i++)
    {
        ApagaAluno(aluno[i]);
    }    

    free(aluno);
    return 0;
}