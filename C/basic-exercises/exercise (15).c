#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    char classe;
    float tarifa, csm;
    printf("Classes Consumidoras | Tarifa (R$)\n");
    printf("%10s%20s\n", "A", "0.5");
    printf("%10s%20s\n", "B", "0.8");
    printf("%10s%20s\n", "C", "1.0");
    printf("Informe a classe consumidora: ");
    scanf("%c", &classe);

    switch (classe)
    {
    case 'A':
    case 'a':
        tarifa = 0.5;
        break;
    case 'B':
    case 'b':
        tarifa = 0.8;
        break;
    case 'C':
    case 'c':
        tarifa = 1.0;
        break;
    default:
        printf("Opção inválida");
        while (getchar() != '\n')
            ;
        getchar();
        return 0;
    }

    printf("Digite o consumo (KWh): ");
    scanf("%f", &csm);

    printf("O Valor a Pagar é de: R$%.2f", 1.3 * (csm * tarifa));
    while (getchar() != '\n');
    getchar();
    return 0;
}