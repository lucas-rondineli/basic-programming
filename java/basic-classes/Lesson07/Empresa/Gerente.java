package lesson07.empresa;

public class Gerente extends Funcionario {
    public Gerente(String nome, double salario, int id) {
        super(nome, salario, id);
        this.salario *= 1.2;
    }
}
