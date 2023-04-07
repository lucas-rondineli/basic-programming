#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    int code, category, bigger_code, subscribers = 0;
    float pulse, total_residencial = 0, total_commercial = 0, most_pulses = 0;

    while (1)
    {
        printf("Digite o código do assinante: ");
        scanf("%d", &code);
        if (code < 0)
            break;
        printf("Digite a quantidade de pulsos: ");
        scanf("%f", &pulse);
        printf("Digite a categoria, 1 - Residencial, 2 - Comercial: ");
        scanf("%d", &category);

        switch (category)
        {
        case 1:
            if (pulse > most_pulses || most_pulses == 0)
            {
                bigger_code = code;
                most_pulses = pulse;
            }

            total_residencial += pulse;
            break;
        case 2:
            subscribers++;

            total_commercial += pulse;
            break;
        default:
            printf("Opção inválida");
            while (getchar() != '\n')
                ;
            getchar();
            return 0;
        }
    }

    printf("\nTotal de residenciais: %.2f\n", total_residencial);
    printf("Total de comercial: %.2f\n", total_commercial);
    printf("Código do assinante com maior número de pulsos residenciais: %d\n", bigger_code);
    printf("Média dos pulsos comerciais: %.2f\n", total_commercial / subscribers);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}