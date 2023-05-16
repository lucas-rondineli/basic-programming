package Lesson07.Escola;

public class Professor extends Pessoa {
    private String disciplina;
    private double salario;

    public Professor(String nome, int idade, String endereco, String disciplina, double salario) {
        super(nome, idade, endereco);
        this.disciplina = disciplina;
        this.salario = salario;
    }

    public void mostreInfo() {
        super.mostreInfo();
        System.out.printf("Disciplina: %s\n", disciplina);
        System.out.printf("Salário: R$%.2f\n", salario);
    }
}
