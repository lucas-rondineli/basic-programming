#include <stdio.h>
#include <locale.h>

typedef struct
{
    int id;
    char desc[100];
    float price;
    int quantity;
} product;

void clearBuffer()
{
    scanf("%*[^\n]");
    scanf("%*c");
}

int edit(product products[])
{
    int optProduct, optEdit;
    printf("\n\tLista de produtos:\n\n");
    for (int i = 0; i < 10; i++)
        printf("\t%d - %s\n", i, products[i].desc);
    do
    {
        printf("\tQual produto deseja editar? ");
        scanf("%d", &optProduct);
        clearBuffer();
        if (optProduct < 0 || optProduct > 10 - 1)
            printf("\tOpção inválida.\n");
    } while (optProduct < 0 || optProduct > 10 - 1);

    printf("\n\tCaracterísticas:\n\n");
    printf("\t1 - Descrição\n");
    printf("\t2 - Preço\n");
    printf("\t3 - Quantidade no Estoque\n");
    printf("\t0 - Cancelar\n");
    do
    {
        printf("\tO que deseja editar? ");
        scanf("%d", &optEdit);
        clearBuffer();
        if (optEdit < 0 || optEdit > 3)
            printf("\tOpção inválida.\n");
    } while (optEdit < 0 || optEdit > 3);

    switch (optEdit)
    {
    case 0:
        printf("\n\tNada foi editado.\n");
        return 0;
    case 1:
        printf("\tInforme a nova descrição: ");
        scanf("%99[^\n]", &products[optProduct].desc);
        break;
    case 2:
        printf("\tInforme o novo preço: ");
        scanf("%f", &products[optProduct].price);
        break;
    case 3:
        printf("\tInforme a nova quantidade: ");
        scanf("%d", &products[optProduct].quantity);
        break;
    }
    printf("\n\tValores alterados com sucesso.\n");
    clearBuffer();
    return 1;
}

int listChar(product products[])
{
    char opt;
    printf("\n\tDigite uma letra: ");
    scanf("%c", &opt);
    clearBuffer();

    int i = 0;
    for (i; i < 10; i++)
        if (products[i].desc[0] == opt)
            break;
    if (i == 10)
    {
        printf("\n\tNão existem produtos nessa lista.");
        return 0;
    }

    printf("\n\tLista de produtos:\n");
    for (i = 0; i < 10; i++)
        if (products[i].desc[0] == opt)
        {
            printf("\n\tID - %d\n", products[i].id);
            printf("\tDescrição - %s\n", products[i].desc);
            printf("\tPreço - R$%.2f\n", products[i].price);
            printf("\tQuantidade - %d\n", products[i].quantity);
        }
    return 1;
}

int listInt(product products[])
{
    int i = 0;
    for (i; i < 10; i++)
        if (products[i].quantity < 5)
            break;
    if (i == 10)
    {
        printf("\n\tNão existem produtos nessa lista.");
        return 0;
    }

    printf("\n\tLista de produtos:\n");
    for (i = 0; i < 10; i++)
        if (products[i].quantity < 5)
        {
            printf("\n\tID - %d\n", products[i].id);
            printf("\tDescrição - %s\n", products[i].desc);
            printf("\tPreço - R$%.2f\n", products[i].price);
            printf("\tQuantidade - %d\n", products[i].quantity);
        }
    return 1;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    product products[10];
    int opt;

    printf("\t ------------------- CADASTRO DOS PRODUTOS -------------------\n");
    for (int i = 0; i < 10; i++)
    {
        products[i].id = i;
        printf("\n\tDigite a descrição do produto %d: ", i + 1);
        scanf(" %99[^\n]", products[i].desc);
        printf("\tDigite o preço do produto %d: R$", i + 1);
        scanf("%f", &products[i].price);
        clearBuffer();
        printf("\tDigite a quantidade produto %d: ", i + 1);
        scanf("%d", &products[i].quantity);
        clearBuffer();
    }

    while (1)
    {
        printf("\n\n\t --------------------------- MENU ---------------------------\n\n");
        printf("\t 1 - Editar Produto\n");
        printf("\t 2 - Listar Produtos por: \"Letra Inicial da Descrição\"\n");
        printf("\t 3 - Listar Produtos com Menos de Cinco Unidades no Estoque.\n");
        printf("\t 0 - Sair.\n");
        printf("\t Informe sua escolha: ");
        scanf("%d", &opt);
        clearBuffer();

        switch (opt)
        {
        case 1:
            edit(products);
            break;
        case 2:
            listChar(products);
            break;
        case 3:
            listInt(products);
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
