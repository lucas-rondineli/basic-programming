#include <stdio.h>
#include <locale.h>
#include <string.h>

void clearBuffer()
{
    while (getchar() != '\n')
        ;
}

void deleteChar(char str[], char c)
{
    char temp[50], tempLen = 0;
    int stringLen = strlen(str);

    for (int i = 0; i < stringLen; i++)
        if (str[i] != c)
            temp[tempLen++] = str[i];
    
    strcpy(str, temp);
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    char str[50], c;

    printf("Digite uma string: ");
    scanf("%49[^\n]", str);
    printf("Digite um caractere: ");
    scanf(" %c", &c);

    deleteChar(str, c);

    printf("Nova string: %s", str);

    clearBuffer();
    getchar();
    return 0;
}
