package Aula06;

import java.util.Scanner;

public class UsaAluno {
    public static void main(String[] Args) {
        String nome;
        double n1, n2, n3;
        Scanner sc = new Scanner(System.in);

        while (true) {
            try {
                System.out.printf("Nome: ");
                nome = sc.nextLine().strip();
                if (nome.length() == 0)
                    throw new Exception();
                break;
            } catch (Exception erro) {
                System.out.printf("Por favor, digite um nome válido.\n\n");
            }
        }

        while (true) {
            try {
                System.out.printf("Nota 1: ");
                n1 = sc.nextDouble();
                if (n1 < 0 || n1 > 30)
                    throw new Exception();
                break;
            } catch (Exception erro) {
                System.out.printf("Por favor, digite uma nota válida, entre 0 e 30.\n\n");
                sc.nextLine();
            }
        }
        sc.nextLine();

        while (true) {
            try {
                System.out.printf("Nota 2: ");
                n2 = sc.nextDouble();
                if (n2 < 0 || n2 > 35)
                    throw new Exception();
                break;
            } catch (Exception erro) {
                System.out.printf("Por favor, digite uma nota válida, entre 0 e 35.\n\n");
                sc.nextLine();
            }
        }
        sc.nextLine();

        while (true) {
            try {
                System.out.printf("Nota 3: ");
                n3 = sc.nextDouble();
                if (n3 < 0 || n3 > 35)
                    throw new Exception();
                break;
            } catch (Exception erro) {
                System.out.printf("Por favor, digite uma nota válida, entre 0 e 35.\n\n");
                sc.nextLine();
            }
        }
        sc.nextLine();

        Aluno aluno = new Aluno(nome, n1, n2, n3);

        System.out.printf("\nNOTA FINAL = %.2f\n", aluno.notaFinal());
        if (aluno.aprovado())
            System.out.printf("PASSOU");
        else {
            System.out.printf("FALHOU\n");
            System.out.printf("NECESSITA DE %.2f PONTOS", aluno.pontosQueFaltam());
        }
        sc.close();
    }
}
