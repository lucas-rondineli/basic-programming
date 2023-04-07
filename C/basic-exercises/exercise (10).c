#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    short int n1, n2, n3;

    printf("Digite 3 valores: ");
    scanf("%hd%hd%hd", &n1, &n2, &n3);
    if (n1 <= n2 && n1 <= n3)
        printf("Soma: %d", n2 + n3);
    else if (n2 <= n1 && n2 <= n3)
        printf("Soma: %d", n1 + n3);
    else
        printf("Soma: %d", n1 + n2);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}