package Aula07.Loja;

public class Computador extends Produto {
    private double memoria;
    private double armazenamento;

    public Computador(String nome, double preco, String descricao, double memoria, double armazenamento) {
        super(nome, preco, descricao);
        this.memoria = memoria;
        this.armazenamento = armazenamento;
    }

    public String mostreInfo() {
        return String.format("Nome: %s\nPreço: R$%.2f\nDescrição: %s\nMemória: %.2fGB\nArmazenamento: %.2fGB\n", nome,
                preco, descricao, memoria, armazenamento);
    }
}
