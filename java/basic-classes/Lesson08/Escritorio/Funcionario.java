package Lesson08.Escritorio;

public abstract class Funcionario {
    protected String nome, matricula;
    protected double salario_base;

    public Funcionario(String nome, String matricula, double salario_base) {
        this.nome = nome;
        this.matricula = matricula;
        this.salario_base = salario_base;
    }

    public abstract double calculaSalario();

    public void mostreInfo() {
        System.out.printf("%-16s| %-10s| R$%-11.2f| R$%.2f\n", nome, matricula, salario_base, calculaSalario());
    }
}
