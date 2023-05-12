package Aula08.Imposto;

public class PessoaJuridica extends Pessoa {
    private int numeroDeFuncionarios;

    public PessoaJuridica(String nome, double renda, int numeroDeFuncionarios) {
        super(nome, renda);
        this.numeroDeFuncionarios = numeroDeFuncionarios;
    }

    public double totalDeImposto() {
        if (numeroDeFuncionarios <= 10)
            return renda * 0.16;

        return renda * 0.14;
    }
}
