#include <stdio.h>
#include <locale.h>

void clearBuffer()
{
    while (getchar() != '\n')
        ;
}

int totalVogal(char str[])
{
    int totalV = 0;
    for (int i = 0; str[i] != '\0'; i++)
        switch (str[i])
        {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            totalV++;
        }
    return totalV;
}

void cryptography(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
        switch (str[i])
        {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            str[i] = '*';
        }
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    char str[50];
    printf("Digite a string: ");
    scanf("%49[^\n]", str);

    printf("A string tem %d vogais\n", totalVogal(str));
    cryptography(str);
    printf("Criptografada: %s\n", str);

    clearBuffer();
    getchar();
    return 0;
}
