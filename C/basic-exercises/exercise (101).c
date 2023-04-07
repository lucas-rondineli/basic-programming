#include <stdio.h>
#include <locale.h>
#include <string.h>

void clearBuffer()
{
    while (getchar() != '\n')
        ;
}

int palindrome(char str[])
{
    int stringLen = strlen(str);
    for (int i = 0; i < stringLen / 2; i++)
        if (str[i] != str[stringLen -1 - i])
            return 0;
    return 1;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    char str[50];

    printf("Digite uma string: ");
    scanf("%49[^\n]", str);

    if (palindrome(str))
        printf("%s é um palindromo", str);
    else
        printf("%s não é um palíndromo", str);

    clearBuffer();
    getchar();
    return 0;
}
