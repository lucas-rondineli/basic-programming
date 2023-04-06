#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    float tot = 0;

    for (float i = 1; i <= 50; i++)
        tot += 1 / i;

    printf("%.2f", tot);

    getchar();
    return 0;
}