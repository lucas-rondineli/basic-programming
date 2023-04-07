#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    float c, s;

    printf("Digite o total de vendas: ");
    scanf("%f", &s);
    c = s * 0.06;
    printf("Digite o salário fixo: ");
    scanf("%f", &s);

    printf("A comissão é de R$%.2f\nO salário final é de R$%.2f\n", c, s + c);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}