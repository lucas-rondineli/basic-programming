#include <stdio.h>
#include <locale.h>

int medidasDoRetangulo(float *A, float *P)
{
    float base = *A, altura = *P;

    *A = base * altura;
    *P = 2 * (base + altura);

    if (base == altura)
        return 1;
    return 0;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    float b, h;

    printf("Digite a base e a altura do retângulo: ");
    scanf("%f%f", &b, &h);

    if (medidasDoRetangulo(&b, &h))
        printf("\nO quadrado tem:\n");
    else
        printf("\nO retângulo tem:\n");

    printf("Área: %.2f\nPerímetro: %.2f", b, h);
    

    while(getchar() != '\n')
        ;
    getchar();
    return 0;
}
