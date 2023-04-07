#include <stdio.h>
#include <locale.h>

void clearBuffer()
{
    scanf("%*[^\n]");
    scanf("%*c");
}

int main()
{
    setlocale(LC_ALL, "portuguese");



    if (getchar() != '\n')
        clearBuffer();
    return 0;
}
