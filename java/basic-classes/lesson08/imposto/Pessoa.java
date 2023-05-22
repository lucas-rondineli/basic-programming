package lesson08.imposto;

public abstract class Pessoa {
    protected String nome;
    protected double renda;

    public Pessoa(String nome, double renda) {
        this.nome = nome;
        this.renda = renda;
    }

    public abstract double totalDeImposto();
}
