package Aula08.Imposto;

public class PessoaFisica extends Pessoa {
    private double gastoComSaude;

    public PessoaFisica(String nome, double renda, double gastoComSaude) {
        super(nome, renda);
        this.gastoComSaude = gastoComSaude;
    }

    public double totalDeImposto() {
        double imposto;
        if (renda < 20000)
            imposto = renda * 0.15;
        else
            imposto = renda * 0.25;

        if (gastoComSaude * 0.5 < imposto)
            return imposto - gastoComSaude * 0.5;
        return 0;
    }
}
