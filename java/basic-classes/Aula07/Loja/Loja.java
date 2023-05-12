package Aula07.Loja;

public class Loja {
    private Validador vd = new Validador();
    private int totalDeProdutos, numeroDeProdutosCadastrados = 0;
    private Produto[] listaDeProdutos;

    public Loja(int totalDeProdutos) {
        this.totalDeProdutos = totalDeProdutos;
        this.listaDeProdutos = new Produto[totalDeProdutos];
    }

    public void adicionarProduto() {
        if (numeroDeProdutosCadastrados != totalDeProdutos) {
            int opt = 0;
            System.out.printf("\nEscolha qual produto deseja cadastrar:\n");
            System.out.printf("1 - Produto Genérico\n");
            System.out.printf("2 - Computador\n");
            System.out.printf("3 - Monitor\n");
            while (true) {
                opt = vd.lerInteiro("Digite um dos números acima: ", "Por favor, digite um número entre 1 e 3.\n\n");
                if (1 <= opt && opt <= 3)
                    break;
                System.out.printf("Por favor, digite um número entre 1 e 3.\n\n");
            }

            String nome = vd.lerString("Digite o nome do produto: ", "Por favor, digite um nome válido.\n\n");
            double preco;
            while (true) {
                preco = vd.lerDouble("Digite o preço do produto: R$", "Por favor, digite um preço válido.\n\n");
                if (preco > 0)
                    break;
                System.out.printf("Por favor, digite um preço válido.\n\n");
            }
            String descricao = vd.lerString("Digite a descrição do produto: ",
                    "Por favor, digite uma descrição válido.\n\n");

            switch (opt) {
                case 1:
                    listaDeProdutos[numeroDeProdutosCadastrados++] = new Produto(nome, preco, descricao);
                    break;
                case 2:
                    double memoria, armazenamento;
                    while (true) {
                        memoria = vd.lerDouble("Digite a memória do produto (GB): ",
                                "Por favor, digite uma memória válida.\n\n");
                        if (memoria > 0)
                            break;
                        System.out.printf("Por favor, digite uma memória válida.\n\n");
                    }
                    while (true) {
                        armazenamento = vd.lerDouble("Digite o armazenamento do produto (GB): ",
                                "Por favor, digite um armazenamento válido.\n\n");
                        if (armazenamento > 0)
                            break;
                        System.out.printf("Por favor, digite um armazenamento válido.\n\n");
                    }
                    listaDeProdutos[numeroDeProdutosCadastrados++] = new Computador(nome, preco, descricao, memoria,
                            armazenamento);
                    break;
                case 3:
                    String resolucao = vd.lerString(
                            "Descreva a resolução do produto (PixeisHorizontais X PixeisVerticais): ",
                            "Por favor, descreva uma resolução válida.\n\n");
                    String tamanhoDeTela = vd.lerString("Descreva o tamanho da tela (Polegadas): ",
                            "Por favor, descreva um tamanho válido.\n\n");
                    listaDeProdutos[numeroDeProdutosCadastrados++] = new Monitor(nome, preco, descricao, resolucao,
                            tamanhoDeTela);
            }
            System.out.printf("Produto Cadastrado com Sucesso.\n\n");
        } else
            System.out.printf("Lista de Produtos cheia, não é possível adicionar mais.\n\n");

    }

    public void listarProdutos() {
        if (numeroDeProdutosCadastrados != 0)
            for (int i = 0; i < numeroDeProdutosCadastrados; i++) {
                System.out.println();
                System.out.printf(listaDeProdutos[i].mostreInfo());
            }
        else
            System.out.printf("Nenhum produto cadastrado no momento.\n\n");
    }
}
