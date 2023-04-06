#include <stdio.h>
#include <locale.h>

void desenha(char c, int l)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < 100; j++)
            printf("%c", c);
        printf("\n");
    }
}


int main()
{
    setlocale(LC_ALL, "portuguese");

    char x;
    int lines;

    printf("Informe um caractere: ");
    x = getchar();
    printf("Informe a quantidade de linhas: ");
    scanf("%d", &lines);

    desenha(x, lines);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
