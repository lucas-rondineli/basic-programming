#include <stdio.h>
#include <locale.h>

void clearBuffer()
{
    while (getchar() != '\n')
        ;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    char str[50], c;
    int oc[50], sizeOC = 0, stringLen = sizeof(str) / sizeof(*str);

    printf("Digite uma string: ");
    scanf("%49[^\n]", str);
    printf("Digite um caractere: ");
    scanf(" %c", &c);


    for (int i = 0; i < stringLen; i++)
        if (str[i] == c)
            oc[sizeOC++] = i;
    oc[sizeOC++] = -1;

    for (int i = 0; i < sizeOC; i++)
        printf("%d ", oc[i]);

    clearBuffer();
    getchar();
    return 0;
}
