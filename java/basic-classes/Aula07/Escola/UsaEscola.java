package Aula07.Escola;

public class UsaEscola {
    public static void main(String[] Args) {
        Pessoa pessoa01 = new Pessoa("Fulano", 20, "Lugar Nenhum");
        Aluno aluno01 = new Aluno("Lucas", 21, "Rua M. D. L.", "2022000****", "Ciências da Computação");
        Professor professor01 = new Professor("Dani", 40, "Rua ...?", "Linguagem de Programação 1", 9999.99);

        pessoa01.mostreInfo();
        System.out.println();
        aluno01.mostreInfo();
        System.out.println();
        professor01.mostreInfo();
    }
}
