package lesson08.escritorio;

public class Assistente extends Funcionario {
    public Assistente(String nome, String matricula, double salario_base) {
        super(nome, matricula, salario_base);
    }

    public double calculaSalario() {
        return salario_base;
    }
}
