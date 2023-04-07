#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    short unsigned int i = 1, n;
    short int number, fat_number, thin_number;
    float mass, fat_mass, thin_mass;

    printf("Informe a quantidade de bois: ");
    scanf("%hu", &n);

    while (i < n + 1)
    {
        printf("Digite o número do %u° boi: ", i);
        scanf("%hd", &number);
        printf("Digite o peso do %u° boi: ", i);
        scanf("%f", &mass);

        if (i == 1 || mass > fat_mass)
        {
            fat_mass = mass;
            fat_number = number;
        }
        if (i == 1 || mass < thin_mass)
        {
            thin_mass = mass;
            thin_number = number;
        }
        i++;
    }

    printf("O boi mais gordo de número '%d' tem %.2f Kg\n", fat_number, fat_mass);
    printf("O boi mais magro de número '%d' tem %.2f Kg\n", thin_number, thin_mass);

    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}