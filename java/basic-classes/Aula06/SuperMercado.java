package Aula06;

import java.util.Scanner;

public class SuperMercado {
    public static void main(String[] Args) {
        ControleProduto sm = new ControleProduto();
        Scanner sc = new Scanner(System.in);
        char opt = 'n';
        int produtoEscolhido, quantia;

        for (int i = 0; i < 10; i++)
            sm.cadastraProduto();

        do {
            for (int i = 0; i < sm.numeroDeProdutos; i++)
                if (sm.produtos[i].quantidade > 0)
                    System.out.printf("\n%02d - %s", i + 1, sm.produtos[i].nome);

            while (true) {
                try {
                    System.out.printf("\nNúmero do Produto: ");
                    produtoEscolhido = sc.nextInt() - 1;
                    if (produtoEscolhido < 0 || produtoEscolhido > sm.numeroDeProdutos || sm.produtos[produtoEscolhido].quantidade == 0)
                        throw new Exception();
                    break;
                } catch (Exception erro) {
                    System.out.printf("Por favor, digite um produto válido.\n");
                    sc.nextLine();
                }
            }
            sc.nextLine();
    
            while (true) {
                try {
                    System.out.printf("\nQuantia a ser Comprada: ");
                    quantia = sc.nextInt();
                    if (quantia < 1 || quantia > sm.produtos[produtoEscolhido].quantidade)
                        throw new Exception();
                    break;
                } catch (Exception erro) {
                    System.out.printf("Por favor, digite uma quantia válida, entre 1 e %d.\n", sm.produtos[produtoEscolhido].quantidade);
                    sc.nextLine();
                }
            }
            sc.nextLine();
    
            sm.efetuaVenda(produtoEscolhido, quantia);

            if (!sm.haEstoque())
                break;
            
            while (true) {
                System.out.printf("Deseja continuar comprando (S/N)? ");
                opt = sc.nextLine().strip().toLowerCase().charAt(0);
                if (opt == 's' || opt == 'n')
                    break;
                System.out.printf("Por favor, digite apenas 'Sim' ou 'Não'.\n\n");
            }
        } while (opt != 'n');

        sc.close();
    }
}
