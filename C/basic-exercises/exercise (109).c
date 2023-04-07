#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void clearBuffer()
{
    scanf("%*[^\n]");
    scanf("%*c");
}

double exponencial(double base, int expoente)
{
    if (expoente == 1)
        return base;
    return base * exponencial(base, expoente - 1);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "portuguese");

    if (argc == 3)
        printf("O valor %s elevado a %s é: %.0f", argv[1], argv[2], exponencial((double)atoi(argv[1]), atoi(argv[2])));
    else
        printf("Erro\n");

    if (getchar() != '\n')
        clearBuffer();
    return 0;
}
