package lesson06.aluno;

public class Aluno {
    private double n1, n2, n3;
    private String nome;

    public Aluno(String nome, double n1, double n2, double n3) {
        this.nome = nome;
        this.n1 = n1;
        this.n2 = n2;
        this.n3 = n3;
    }

    public double notaFinal() {
        return n1 + n2 + n3;
    }

    public boolean aprovado() {
        if (notaFinal() >= 60)
            return true;
        return false;
    }

    public double pontosQueFaltam() {
        if (!aprovado())
            return 60 - notaFinal();
        return 0;
    }
}
