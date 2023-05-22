package lesson07.loja;

public class Monitor extends Produto {
    private String resolucao;
    private String tamanhoDeTela;

    public Monitor(String nome, double preco, String descricao, String resolucao, String tamanhoDeTela) {
        super(nome, preco, descricao);
        this.resolucao = resolucao;
        this.tamanhoDeTela = tamanhoDeTela;
    }

    public String mostreInfo() {
        return String.format("Nome: %s\nPreço: R$%.2f\nDescrição: %s\nResolução: %s\nTamanho da Tela: %s Polegadas\n",
                nome, preco, descricao, resolucao, tamanhoDeTela);
    }
}
