#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    short unsigned int opt;
    short int x, y;

    printf("Menu de opções:\n\t1 - Somar dois números;\n\t2 - Raiz quadrada de um número;\n\tDigite a opção desejada: ");
    scanf("%hu", &opt);

    switch (opt)
    {
    case 1:
        printf("Digite dois números: ");
        scanf("%hd%hd", &x, &y);
        printf("Soma: %d", x + y);
        break;
    case 2:
        printf("Digite um número: ");
        scanf("%hd", &x);
        printf("Raiz Quadrada: %.2f", sqrt(x));
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