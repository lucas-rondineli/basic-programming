package Aula06;

public class Funcionario {
    private String nome;
    private double salarioBruto, imposto;

    public Funcionario(String nome, double salarioBruto, double imposto) {
        this.nome = nome;
        this.salarioBruto = salarioBruto;
        this.imposto = imposto;
    }

    public double calculaSalarioLiquido() {
        return salarioBruto - imposto;
    }

    public void aumentaSalario(double percentual) {
        salarioBruto *= (1 + percentual / 100);
    }

    public String mostrarDados() {
        return String.format("%s, R$%.2f", nome, calculaSalarioLiquido());
    }
}
