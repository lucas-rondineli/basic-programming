package Lesson07.Empresa;

public class Funcionario {
    protected String nome;
    protected double salario;
    protected int id;

    public Funcionario(String nome, double salario, int id) {
        this.nome = nome;
        this.salario = salario;
        this.id = id;
    }

    public void mostreInfo() {
        System.out.printf("Nome: %s\nSalário: R$%.2f\n", nome, salario);
    }
}
