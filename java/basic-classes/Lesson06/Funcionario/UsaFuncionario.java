package Lesson06.Funcionario;

import java.util.Scanner;

public class UsaFuncionario {
    public static void main(String[] Args) {
        Scanner sc = new Scanner(System.in);
        String nome;
        double salarioBruto, imposto, percentual;

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
                System.out.printf("Salário bruto (R$): ");
                salarioBruto = sc.nextDouble();
                if (salarioBruto <= 0)
                    throw new Exception();
                break;
            } catch (Exception erro) {
                System.out.printf("Por favor, digite um salário válido.\n\n");
                sc.nextLine();
            }
        }
        sc.nextLine();

        while (true) {
            try {
                System.out.printf("Imposto: ");
                imposto = sc.nextDouble();
                if (imposto < 0 || imposto > salarioBruto)
                    throw new Exception();
                break;
            } catch (Exception erro) {
                System.out.printf("Por favor, digite um imposto válido. Ele não pode ser maior que o salário.\n\n");
                sc.nextLine();
            }
        }
        sc.nextLine();

        Funcionario funcionario = new Funcionario(nome, salarioBruto, imposto);

        System.out.printf("\nEmpregado: %s\n\n", funcionario.mostrarDados());

        while (true) {
            try {
                System.out.printf("Qual o percentual para aumentar o salário? ");
                percentual = sc.nextDouble();
                if (percentual <= 0)
                    throw new Exception();
                break;
            } catch (Exception erro) {
                System.out.printf("Por favor, digite um percentual válido. Ele deve ser positivo.\n\n");
                sc.nextLine();
            }
        }
        sc.nextLine();

        funcionario.aumentaSalario(percentual);
        System.out.printf("\nDados atualizados:\n%s", funcionario.mostrarDados());

        sc.close();
    }
}
