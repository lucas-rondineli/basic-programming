#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    short int x, y, opt;

    printf("Digite dois números: ");
    scanf("%hd%hd", &x, &y);
    printf("\nOpções:\n");
    printf("1.Adição\n");
    printf("2.Subtração\n");
    printf("3.Divisão\n");
    printf("4.Produto\n");
    printf("Escolha uma: ");
    scanf("%hd", &opt);
    printf("\n");

    switch (opt)
    {
    case 1:
        printf("Soma: %d", x + y);
        break;
    case 2:
        printf("Subtração: %d", x - y);
        break;
    case 3:
        if (y != 0)
            printf("Divisão: %d", x / y);
        else
            printf("Não se pode dividir por 0");
        break;
    case 4:
        printf("Produto: %d", x * y);
        break;
    default:
        printf("Opção inválida");
        while (getchar() != '\n')
            ;
        getchar();
        return 0;
    }

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}