#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    
    char s;
    float h, big, small, htotf = 0;
    short int totm = 0, totf = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("Digite a altura: ");
        scanf("%f", &h);
        printf("Digite o sexo [M/F]: ");
        scanf(" %c", &s);

        if (h > big || i == 0)
            big = h;
        if (h < small || i == 0)
            small = h;

        switch (s)
        {
        case 'M':
        case 'm':
            totm++;
            break;
        case 'F':
        case 'f':
            htotf += h;
            totf++;
            break;
        default:
            printf("\nOpção inválida");
            while (getchar() != '\n')
                ;
            getchar();
            return 0;
        }
    }

    printf("A maior altura: %.2f\nA menor altura: %.2f\n", big, small);
    printf("Média da altura das mulheres: %.2f\n", htotf / totf);
    printf("O número de homens: %d", totm);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}