#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    int v[10], s = 0;

    printf("Digite 10 valores: ");
    
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &v[i]);
        s += v[i];
    }

    printf("A soma foi de: %d", s);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
