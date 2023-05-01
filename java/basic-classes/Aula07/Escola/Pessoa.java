package Aula07.Escola;

public class Pessoa {
    protected String nome;
    protected int idade;
    protected String endereco;

    public Pessoa(String nome, int idade, String endereco) {
        this.nome = nome;
        this.idade = idade;
        this.endereco = endereco;
    }

    public void mostreInfo() {
        System.out.printf("Nome: %s\n", nome);
        System.out.printf("Idade: %d\n", idade);
        System.out.printf("Endereço: %s\n", endereco);
    }
}
