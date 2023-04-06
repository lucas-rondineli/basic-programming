#include <stdio.h>
#include <string.h>
#include <locale.h>

#define DEBUG 1

typedef struct
{
    char brand[20];
    int year;
    char color[20];
    float price;
} car;

void clearBuffer()
{
    scanf("%*[^\n]");
    scanf("%*c");
}

void readCars(car cars[])
{
    printf("\n\t ------------------- CADASTRO DOS CARROS -------------------\n");
    for (int i = 0; i < DEBUG; i++)
    {
        printf("\n\tDigite a marca do carro %d: ", i + 1);
        scanf(" %19[^\n]", cars[i].brand);
        printf("\tDigite o ano do carro %d: ", i + 1);
        scanf("%d", &cars[i].year);
        clearBuffer();
        printf("\tDigite a cor do carro %d: ", i + 1);
        scanf(" %19[^\n]", cars[i].color);
        printf("\tDigite o preço do carro %d: R$", i + 1);
        scanf("%f", &cars[i].price);
        clearBuffer();
    }
}

int listPrice(car cars[])
{
    float price;
    printf("\n\tDigite um preço: R$");
    scanf("%f", &price);
    clearBuffer();

    int i = 0;
    for (i; i < DEBUG; i++)
        if (cars[i].price <= price)
            break;
    if (i == DEBUG)
    {
        printf("\n\tNão existem carros nessa faixa de preço.\n");
        return 0;
    }

    for (i = 0; i < DEBUG; i++)
        if (cars[i].price <= price)
        {
            printf("\n\tMarca: %s\n", cars[i].brand);
            printf("\tCor: %s\n", cars[i].color);
            printf("\tAno: %d\n", cars[i].year);
        }
    return 1;
}
int listBrand(car cars[])
{
    char brand[20];
    printf("\n\tDigite uma marca: ");
    scanf("%19[^\n]", brand);

    int i = 0;
    for (i; i < DEBUG; i++)
        if (!strcmp(cars[i].brand, brand))
            break;
    if (i == DEBUG)
    {
        printf("\n\tNão existem carros dessa marca.\n");
        return 0;
    }

    for (i = 0; i < DEBUG; i++)
        if (!strcmp(cars[i].brand, brand))
        {
            printf("\n\tPreço: R$%.2f\n", cars[i].price);
            printf("\tAno: %d\n", cars[i].year);
            printf("\tCor: %s\n", cars[i].color);
        }
    return 1;
}
int searchCar(car cars[])
{
    char brand[20], color[20];
    int year;
    printf("\n\tDigite uma marca: ");
    scanf("%19[^\n]", brand);
    printf("\tDigite um ano: ");
    scanf("%d", &year);
    clearBuffer();
    printf("\tDigite uma cor: ");
    scanf("%19[^\n]", color);

    for (int i = 0; i < DEBUG; i++)
        if (!strcmp(cars[i].brand, brand) && cars[i].year == year && !strcmp(cars[i].color, color))
        {
            printf("\tExiste um carro com essas características e o preço é R$%.2f\n", cars[i].price);
            return 1;
        }
    printf("\n\tNão existe um carro com essas características.\n");
    return 0;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    car cars[DEBUG];
    int opt;

    readCars(cars);

    while (1)
    {
        printf("\n\n\t --------------------------- MENU ---------------------------\n\n");
        printf("\t 1 - Recadastrar os Carros\n");
        printf("\t 2 - Listar carros por preço\n");
        printf("\t 3 - Listar carros por marca\n");
        printf("\t 4 - Procurar Carro Específico\n");
        printf("\t 0 - Sair.\n");
        printf("\t Informe sua escolha: ");
        scanf("%d", &opt);
        clearBuffer();

        switch (opt)
        {
        case 1:
            readCars(cars);
            break;
        case 2:
            listPrice(cars);
            break;
        case 3:
            listBrand(cars);
            break;
        case 4:
            searchCar(cars);
            break;
        case 0:
            break;
        default:
            printf("\n\tOpção inválida.");
        }
        if (opt == 0)
            break;
    }

    printf("\n\tObrigado, volte sempre!");
    getchar();
    return 0;
}
