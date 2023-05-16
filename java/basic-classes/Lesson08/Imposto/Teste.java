package Lesson08.Imposto;

import java.util.Scanner;

public class Teste {
    private static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int totalContribuintes;
        while (true) {
            totalContribuintes = validaInt("Entre com o número de contribuintes: ",
                    "Por favor, digite apenas um número inteiro maior que 0.\n\n");
            if (totalContribuintes > 0)
                break;
            System.out.printf("Por favor, digite apenas um número inteiro maior que 0.\n\n");
        }

        Pessoa[] pessoas = new Pessoa[totalContribuintes];
        String nome;
        double renda, saude;
        int funcionarios, tipoDeFuncionario;
        for (int i = 0; i < totalContribuintes; i++) {
            while (true) {
                tipoDeFuncionario = validaInt(String.format("\nA %do pessoa é Física (1) ou Jurídica (2)? ", i + 1),
                        "Por favor, digite apenas 1 ou 2.\n\n");
                if (tipoDeFuncionario == 1 || tipoDeFuncionario == 2)
                    break;
                System.out.printf("Por favor, digite apenas 1 ou 2.\n\n");
            }
            nome = validaString("Entre com o nome do funcionário: ", "Por favor, digite um nome válido.\n\n");
            renda = validaDinheiro("Entre com a renda do funcionário: R$",
                    "Por favor, digite um salário maior ou igual que 0.\n\n");
            if (tipoDeFuncionario == 1) {
                saude = validaDinheiro("Entre com o total de gastos com saúde: R$",
                        "Por favor, digite um total maior ou igual a 0.\n\n");
                pessoas[i] = new PessoaFisica(nome, renda, saude);
            } else {
                while (true) {
                    funcionarios = validaInt("Entre com o total de funcionários: ",
                            "Por favor, digite um total maior ou igual a 0.\n\n");
                    if (funcionarios >= 0)
                        break;
                    System.out.printf("Por favor, digite um total maior ou igual a 0.\n\n");
                }
                pessoas[i] = new PessoaJuridica(nome, renda, funcionarios);
            }
        }

        System.out.println();
        double totalArrecadado = 0;
        for (int i = 0; i < totalContribuintes; i++) {
            System.out.printf("Imposto do funcionário %d: R$%.2f\n", i + 1, pessoas[i].totalDeImposto());
            totalArrecadado += pessoas[i].totalDeImposto();
        }
        System.out.printf("Total de Imposto Arrecadado: R$%.2f\n", totalArrecadado);


        sc.close();
    }

    private static int validaInt(String msg, String err) {
        int aux;
        while (true)
            try {
                System.out.printf(msg);
                aux = sc.nextInt();
                break;
            } catch (Exception e) {
                System.out.printf(err);
                sc.nextLine();
            }
        sc.nextLine();
        return aux;
    }

    private static String validaString(String msg, String err) {
        String aux;
        while (true)
            try {
                System.out.printf(msg);
                aux = sc.nextLine().strip();
                if (aux.length() > 0)
                    break;
                throw new Exception();
            } catch (Exception e) {
                System.out.printf(err);
            }
        return aux;
    }

    private static double validaDinheiro(String msg, String err) {
        double aux;
        while (true)
            try {
                System.out.printf(msg);
                aux = sc.nextDouble();
                if (aux >= 0)
                    break;
                throw new Exception();
            } catch (Exception e) {
                System.out.printf(err);
                sc.nextLine();
            }
        sc.nextLine();
        return aux;
    }
}
