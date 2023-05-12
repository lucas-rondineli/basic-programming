package Aula08.Escritorio;

public class Gerente extends Funcionario {
    public Gerente(String nome, String matricula, double salario_base) {
        super(nome, matricula, salario_base);
    }

    public double calculaSalario() {
        return 2 * salario_base;
    }
}
