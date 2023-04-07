#include <stdio.h>
#include <locale.h>

float ideal(float h, char s)
{
    switch (s)
    {
    case 'M':
    case 'm':
        h = 72.7 * h - 58;
        break;
    case 'F':
    case 'f':
        h = 62.1 * h - 44.7;
        break;
    }
    return h;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    float height;
    char sex;

    printf("Digite a altura: ");
    scanf("%f", &height);
    printf("Digite o sexo [M/F]: ");
    scanf(" %c", &sex);

    printf("Seu peso ideal é: %.2f", ideal(height, sex));

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}