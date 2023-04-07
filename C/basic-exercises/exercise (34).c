#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    short int highest_age = 0, age, population = 0, spcf = 0;
    char sex, eye_color, hair_color;

    while (1)
    {
        printf("Digite o sexo [M/F]: ");
        scanf(" %c", &sex);
        printf("Digite a cor dos olhos [A - Azuis, V - Verdes, C - Castanhos]: ");
        scanf(" %c", &eye_color);
        printf("Digite a cor dos cabelos [L - Loiros, C - Castanhos, P - Pretos]: ");
        scanf(" %c", &hair_color);
        printf("Digite a idade: ");
        scanf("%hd", &age);

        if (age == -1)
            break;

        population++;
        if (age > highest_age)
            highest_age = age;
        if ((sex == 'F' || sex == 'f') && age >= 18 && age <= 35 && (eye_color == 'V' || eye_color == 'v') && (hair_color == 'L' || hair_color == 'l'))
            spcf++;
    }

    printf("A pessoa com a maior idade da população tem %d anos\n", highest_age);
    printf("A porcentagem de indivíduos que são Mulheres, Loiras, de olhos Verdes, entre 18 e 35 anos, é de: %.2f\%", ((float) spcf / population) * 100);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}