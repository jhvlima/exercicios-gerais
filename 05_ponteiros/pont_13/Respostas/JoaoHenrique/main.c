#include <stdio.h>

typedef struct
{
    char mensagem[TAM_MAX_MSG];
}tMensagens;

int main()
{
    tMensagens entrada[NUM_MAX_MSGS];
    int qtd_mensagens, tempo;
    scanf("%d", &qtd_mensagens);
    for (int i = 0; i < qtd_mensagens; i++)
    {
        scanf("[%^\n]", entrada[i]);
    }
    scanf("%d", &tempo);
    return 0;
}