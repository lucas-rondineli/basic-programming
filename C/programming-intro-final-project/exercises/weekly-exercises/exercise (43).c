#include <stdio.h>
#include <locale.h>

int ajuste(int d, int m, int a, int opt)
{
    // Tratamento de erros de entrada
    if (d < 1 || m < 1 || m > 12 || (opt != 1 && opt != 2))
    {
        printf("Entrada inválida");
        while (getchar() != '\n')
            ;
        getchar();
        return 0;
    }

    // Mais tratamentos de erros de entrada
    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (d <= 31)
            break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (d <= 30)
            break;
    case 2:
        if (((a % 4 == 0 && a % 100 != 0 || a % 400 == 0) && d <= 29) || d <= 28)
            break;
    default:
        printf("Entrada inválida");
        while (getchar() != '\n')
            ;
        getchar();
        return 0;
    }

    // Mudança de dias
    switch (opt)
    {
    case 1:
        d += 5;
        break;
    case 2:
        d -= 5;
    }
    // Correção de diminuição de mês ou ano
    if (d < 1)
    {
        m -= 1;
        if (m < 1)
        {
            a -= 1;
            m = 12;
        }
    }
    // Correção de dias e aumento de mês ou ano
    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (d < 1)
            d = 31 + d;
        if (d > 31)
        {
            m += 1;
            if (m > 12)
            {
                a += 1;
                m = 1;
            }
            d = d - 31;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (d < 1)
            d = 30 + d;
        if (d > 30)
        {
            m += 1;
            d = d - 30;
        }
    case 2:
        // Caso dos anos bissextos
        if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
        {
            if (d < 1)
                d = 29 + d;
            if (d > 29)
            {
                m += 1;
                d = d - 29;
            }
        }
        else
        {
            if (d < 1)
                d = 28 + d;
            if (d > 28)
            {
                m += 1;
                d = d - 28;
            }
        }
    }

    // Saída final
    printf("Dia/Mês/Ano: %02d/%02d/%04d", d, m, a);
    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    int dia, mes, ano, opt;
    printf("Digite o dia, mes e ano: ");
    scanf("%d%d%d", &dia, &mes, &ano);
    printf("Cinco dias a mais (1) ou a menos (2)? ");
    scanf("%d", &opt);

    ajuste(dia, mes, ano, opt);
    return 0;
}