#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    float x, y, z;
    printf("Digite três comprimentos: ");
    scanf("%f%f%f", &x, &y, &z);

    if (!(x < y + z && y < x + z && z < x + y))
        printf("Os valores não formam um triângulo");
    else if (x == y && y == z)
        printf("Forma um Triângulo Equilátero");
    else if (x == y || y == z || x == z)
        printf("Forma um Triângulo Isóceles");
    else
        printf("Forma um Triângulo Escaleno");

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}