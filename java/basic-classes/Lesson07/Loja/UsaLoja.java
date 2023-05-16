package Lesson07.Loja;

public class UsaLoja {
    public static void main(String[] Args) {
        Validador vd = new Validador();
        Loja loja01 = new Loja(5);
        int opt = 0;
        while (true) {
            System.out.printf("\nEscolha uma opção:\n");
            System.out.printf("1 - Adicionar um Produto\n");
            System.out.printf("2 - Listar os Produtos\n");
            System.out.printf("0 - Sair do Programa\n");
            while (true) {
                opt = vd.lerInteiro("Digite um dos números acima: ", "Por favor, digite um número entre 0 e 2.\n\n");
                if (0 <= opt && opt <= 2)
                    break;
                System.out.printf("Por favor, digite um número entre 0 e 2.\n\n");
            }

            if (opt == 0)
                break;
            switch (opt) {
                case 1:
                    loja01.adicionarProduto();
                    break;
                case 2:
                    loja01.listarProdutos();
            }
        }
        System.out.printf("\nFim Do Programa. Obrigado, volte sempre!\n");
    }
}
