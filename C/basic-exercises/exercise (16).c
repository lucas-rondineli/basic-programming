#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    for (int i = 50; i <= 65; i++)
        printf("%d F = %.2f C\n", i, (i - 32) / 1.8);

    getchar();
    return 0;
}