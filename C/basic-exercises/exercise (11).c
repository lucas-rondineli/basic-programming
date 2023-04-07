#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    short unsigned int m1, m2, w1, w2, tot;
    printf("Digite a idade dos homens: ");
    scanf("%hu%hu", &m1, &m2);
    printf("Digite a idade das mulheres: ");
    scanf("%hu%hu", &w1, &w2);

    if (m1 > m2)
        tot += m1;
    else
        tot += m2;
    if (w1 < w2)
        tot += w1;
    else
        tot += w2;
    printf("A idade somada é: %u", tot);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}