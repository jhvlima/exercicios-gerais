#include <stdio.h>
#include "evento.h"

void imprimeMenu()
{
    printf("\n===== Menu =====\n");
    printf("1 - Cadastrar um evento\n");
    printf("2 - Exibir todos os eventos\n");
    printf("3 - Trocar data de um evento\n");
    printf("4 - Trocar a posicao entre dois eventos\n");
    printf("5 - Sair\n");
}

int main()
{
    Evento eventos[MAX_EVENTOS];
    int numEventos = 0;
    int *pnumEventos = &numEventos;
    int opcao = 0;

    imprimeMenu();

    while (opcao != 5)
    {
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarEvento(eventos, pnumEventos);
            break;
        case 2:
            exibirEventos(eventos, pnumEventos);
            break;
        case 3:
            trocarDataEvento(eventos, pnumEventos);
            break;
        case 4:
            int indiceA, indiceB;
            int *pA = &indiceA, *pB = &indiceB;
            scanf("%d %d", &indiceA, &indiceB);
            trocarIndicesEventos(eventos, pA, pB, pnumEventos);
            break;
        case 5:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }
    }

    return 0;
}