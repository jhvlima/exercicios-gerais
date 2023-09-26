

#include <stdio.h>

int main()
{
    char nome[100];
    char partido[100];
    char cargo;
    int id;
    scanf("%[^,] %*[^A-Za-z] %[^,] %*[^A-Za-z] %c %*c %d", nome, partido, &cargo, &id);

    printf("%s\n", nome);
    printf("%s\n", partido);
    printf("%c\n", cargo);
    printf("%d\n", id);

    return 0;
}