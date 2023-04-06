#include <stdio.h>
#include <locale.h>
#include <string.h>

void clearBuffer()
{
    while (getchar() != '\n')
        ;
}

int totalWords(char phrase[])
{
    int totSpaces = 1, i = 1;

    for (i; phrase[i] != '\0'; i++)
        if (phrase[i] == ' ' && phrase[i - 1] != ' ')
            totSpaces++;
    if (phrase[i - 1] == ' ')
        totSpaces--;
    return totSpaces;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    char phrase[50] = "";

    printf("Digite uma frase: ");
    scanf(" %49[^\n]", phrase);

    printf("O total de palavras na frase é de: %d\n", totalWords(phrase));

    clearBuffer();
    getchar();
    return 0;
}
