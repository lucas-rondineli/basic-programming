#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    char sex, answer;
    short int yes = 0, no = 0, totm = 0, totf = 0, totnom = 0, totyesf = 0;

    for (int i = 0; i < 20; i++)
    {
        printf("Digite o sexo [M/F]: ");
        scanf(" %c", &sex);
        printf("Digite a resposta [S/N]: ");
        scanf(" %c", &answer);

        switch (answer)
        {
        case 'S':
        case 's':
            yes++;
            break;
        case 'N':
        case 'n':
            no++;
            break;
        default:
            printf("Opção inválida");
            while (getchar() != '\n')
                ;
            getchar();
            return 0;
        }

        switch (sex)
        {
        case 'M':
        case 'm':
            if (answer == 'N' || answer == 'n')
                totnom++;
            totm++;
            break;
        case 'F':
        case 'f':
            if (answer == 'S' || answer == 's')
                totyesf++;
            totf++;
            break;
        default:
            printf("Opção inválida");
            while (getchar() != '\n')
                ;
            getchar();
            return 0;
        }
    }

    printf("Total de Sim: %hd\n", yes);
    printf("Total de Não: %hd\n", no);
    printf("Porcentagem de Mulheres que responderam Sim: %.2f \%\n", ((float) totyesf / totf) * 100);
    printf("Porcentagem de Homens que responderam Não: %.2f \%\n", ((float) totnom / totm) * 100);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}