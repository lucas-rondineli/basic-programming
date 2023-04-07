#include <stdio.h>
#include <locale.h>

int tri(float a, float b, float c)
{
    if (a >= b + c || b >= a + c || c >= a + b)
        return -1;
    if (a == b && b == c)
        return 0;
    if (a == b || b == c || a == c)
        return 1;
    return 2;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    float a, b, c;
    printf("Digite os 3 lados do triângulo: ");
    scanf("%f%f%f", &a, &b, &c);

    printf("%d", tri(a, b, c));

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}