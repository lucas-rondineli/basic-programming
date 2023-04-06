#include <stdio.h>
#include <locale.h>

void clearBuffer()
{
    while (getchar() != '\n')
        ;
}

int ocorrency(char str[], char character)
{
    int total = 0, i = 0;
    for (i; str[i] != '\0'; i++)
        if (str[i] == character)
            total++;
    return total;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    char str[50], charactere;
    int total;

    printf("Digite a string: ");
    scanf("%49[^\n]", str);

    printf("Digite o charactere: ");
    scanf(" %c", &charactere);

    total = ocorrency(str, charactere);
    printf("O caractere %c aparece %d vezes na string %s", charactere, total, str);

    clearBuffer();
    getchar();
    return 0;
}
