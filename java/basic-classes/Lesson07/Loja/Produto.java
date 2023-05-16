package Lesson07.Loja;

public class Produto {
    protected String nome;
    protected double preco;
    protected String descricao;

    public Produto(String nome, double preco, String descricao) {
        this.nome = nome;
        this.preco = preco;
        this.descricao = descricao;
    }

    public String mostreInfo() {
        return String.format("Nome: %s\nPreço: R$%.2f\nDescrição: %s\n", nome, preco, descricao);
    }
}
