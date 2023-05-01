package Aula06.Mercado;

import java.util.Scanner;

public class ControleProduto {
    public Produto[] produtos = new Produto[10];
    public int numeroDeProdutos = 0;
    private Scanner sc = new Scanner(System.in);

    public void efetuaVenda(int produto, int quantidade) {
        produtos[produto].quantidade -= quantidade;
    }

    public boolean cadastraProduto() {
        if (numeroDeProdutos == 10)
            return false;
        
        String nome;
        int quantidade;
        double preco;

        while (true) {
            try {
                System.out.printf("\nNome do Produto: ");
                nome = sc.nextLine().strip();
                if (nome.length() == 0)
                    throw new Exception();
                break;
            } catch (Exception erro) {
                System.out.printf("Por favor, digite um nome válido.\n");
            }
        }

        while (true) {
            try {
                System.out.printf("Quantidade do Produto: ");
                quantidade = sc.nextInt();
                if (quantidade <= 0)
                    throw new Exception();
                break;
            } catch (Exception erro) {
                System.out.printf("Por favor, digite uma quantidade válida.\n\n");
                sc.nextLine();
            }
        }
        sc.nextLine();

        while (true) {
            try {
                System.out.printf("Preço do Produto (R$): ");
                preco = sc.nextDouble();
                if (preco <= 0)
                    throw new Exception();
                break;
            } catch (Exception erro) {
                System.out.printf("Por favor, digite um preço válido.\n\n");
                sc.nextLine();
            }
        }
        sc.nextLine();

        produtos[numeroDeProdutos++] = new Produto(nome, quantidade, preco);
        return true;
    }

    public boolean haEstoque() {
        for (int i = 0; i < numeroDeProdutos; i++)
            if (produtos[i].quantidade > 0)
                return true;
        return false;
    }
}
