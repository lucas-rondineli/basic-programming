#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

void studly(char str[])
{
    int stringLen = strlen(str), pos;

    for (int i = 0; i < stringLen; i++)
    {
        pos = rand() % stringLen;
        str[pos] = str[pos] >= 'a' && str[pos] <= 'z'  ? toupper(str[pos]) : tolower(str[pos]);
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    char str[50];
    printf("Digite uma string: ");
    scanf("%49[^\n]", str);

    studly(str);

    printf("Nova string: %s", str);

    scanf("%*[^\n]");
    scanf("%*c");
    getchar();
    return 0;
}
