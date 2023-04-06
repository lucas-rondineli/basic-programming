#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    short unsigned int i = 0;
    short int n;

    printf("Digite um número: ");
    scanf("%hd", &n);

    printf("Os multiplos de 3 e 5 entre 1 e %d são: ", n);
    while (i <= n)
    {
        if (i % 15 == 0)
            printf("%u ", i);
        i++;
    }

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}