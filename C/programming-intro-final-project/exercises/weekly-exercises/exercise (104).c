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

    

    clearBuffer();
    getchar();
    return 0;
}
