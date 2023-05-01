package Aula07.Escola;

public class Aluno extends Pessoa {
    private String matricula;
    private String curso;

    public Aluno(String nome, int idade, String endereco, String matricula, String curso) {
        super(nome, idade, endereco);
        this.matricula = matricula;
        this.curso = curso;
    }

    public void mostreInfo() {
        super.mostreInfo();
        System.out.printf("Matrícula: %s\n", matricula);
        System.out.printf("Curso: %s\n", curso);
    }
}
