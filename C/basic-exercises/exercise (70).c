#include <stdio.h>
#include <locale.h>
#include <stdlib.h> // necessário p/ as funções rand() e srand()
#include <time.h>   //necessário p/ função time()

int main()
{
    setlocale(LC_ALL, "portuguese");

    printf("Gerando 10 valores aleatorios:\n\n");

    /* srand(time(NULL)) objetiva inicializar o gerador de números aleatórios
    com o valor da função time(NULL). Este por sua vez, é calculado
    como sendo o total de segundos passados desde 1 de janeiro de 1970
    até a data atual.
    Desta forma, a cada execução o valor da "semente" será diferente.
    */
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
        // gerando valores aleatórios na faixa de 0 a 100
        printf("%d ", rand() % 100);

    getchar();
    return 0;
}