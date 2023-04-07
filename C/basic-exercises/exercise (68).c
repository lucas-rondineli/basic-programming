#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    int v[20], maior, maiorPosicao;

    for (int i = 0; i < 20; i++)
    {
        v[i] = rand() % 100;
        if (v[i] > maior || i == 0)
        {
            maior = v[i];
            maiorPosicao = i;
        }
    }
    
    printf("Vetor: ");
    for (int i = 0; i < 20; i++)
        printf("%d ", v[i]);
    printf("\nO maior número é: %d\nE sua posição é: %d", maior, maiorPosicao);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}
