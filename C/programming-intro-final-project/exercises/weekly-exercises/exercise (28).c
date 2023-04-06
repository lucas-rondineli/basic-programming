#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    float x, tmv, mi, mf;
    printf("Digite a massa inicial do material radiotivo: ");
    scanf("%f", &mi);
    printf("Digite a massa final do material radiotivo: ");
    scanf("%f", &mf);
    printf("Digite o tempo de meia-vida do material radiotivo: ");
    scanf("%f", &tmv);

    x = log2(mi / mf);
    x *= tmv;

    printf("Para qualquer tempo acima de %.2f, o material radioativo terá menos de %.2f de massa", x, mf);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}