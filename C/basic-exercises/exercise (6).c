#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");

    int code;
    float price, sum_vista = 0, sum_prazo = 0;

   while (1)
   {
    printf("\nDigite o código da venda [1. À vista, 2. À prazo, 0. Parar]: ");
    scanf("%d", &code);
    if (code == 0)
        break;
    if (code != 0 && code != 1 && code != 2)
    {
        printf("Opção inválida");
        while (getchar() != '\n')
            ;
        getchar();
        return 0;
    }
    
    
    printf("Digite o valor da venda: R$");
    scanf("%f", &price);

    switch (code)
    {
    case 1:
        sum_vista += price;
        break;
    case 2:
        sum_prazo += price;
        break;
    }    
   }

   printf("\nO total de vendas à vista foi: %.2f\n", sum_vista);
   printf("O total de vendas à prazo foi: %.2f\n", sum_prazo);
   printf("O total de vendas no total foi: %.2f\n", sum_vista + sum_prazo);
   
    while (getchar() != '\n')
        ;
    getchar();
    return 0;
}