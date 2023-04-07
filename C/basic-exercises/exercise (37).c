#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    float mi, mf, t = 0;

    printf("Informe a massa inicial: ");
    scanf("%f", &mi);
    mf = mi;

    while (mf >= 0.5)
    {
        t++;
        mf /= 2;
    }

    printf("Massa inicial: %.2f\n", mi);
    printf("Massa final: %.2f\n", mf);
    printf("Tempo: %.2f\n", t * 50);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}