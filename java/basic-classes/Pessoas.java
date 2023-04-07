import java.util.Scanner;

public class Pessoas {
    final static int NUMERO_DE_PESSOAS = 5;
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] Args) {
        String[] nomes = new String[NUMERO_DE_PESSOAS];
        int[] idades = new int[NUMERO_DE_PESSOAS];
        float[] alturas = new float[NUMERO_DE_PESSOAS], pesos = new float[NUMERO_DE_PESSOAS];
        int opt = 0;

        do {
            System.out.println("\nMenu");
            System.out.println("[1] Cadastro de Pessoas");
            System.out.println("[2] Lista de Pessoas Cadastrados");
            System.out.println("[3] Análise da Média de Dados");
            System.out.println("[4] Valores de IMC");
            System.out.println("[5] Valores das Idades");
            System.out.println("[7] Dado da Pessoa");
            System.out.println("[8] Sair");
            System.out.print("\nPor favor, digite um número entre os citados: ");
            opt = sc.nextInt();
            sc.nextLine();

            switch (opt) {
                case 1:
                    cadastroDePessoas(nomes, idades, alturas, pesos);
                    break;
                case 2:
                    listarPessoas(nomes, idades, alturas, pesos);
                    break;
                case 3:
                    mediaDosDados(idades, alturas, pesos);
                    break;
                case 4:
                    IMC(nomes, alturas, pesos, idades);
                    break;
                case 5:
                    valoresIdades(nomes, idades);
                    break;
                case 7:
                    dadoDaPessoa(nomes, idades, alturas, pesos);
                    break;
                case 8:
                    break;
                default:
                    System.out.print("\nErro, opção inválida.\n");
            }

        } while (opt != 8);
    }

    static void cadastroDePessoas(String[] nomes, int[] idades, float[] alturas, float[] pesos) {

        for (int i = 0; i < NUMERO_DE_PESSOAS; i++) {
            System.out.printf("\nPessoa %02d\n", i + 1);

            System.out.print("Digite o nome e sobrenome: ");
            nomes[i] = sc.nextLine().trim();

            System.out.print("Digite a idade da pessoa: ");
            idades[i] = sc.nextInt();
            sc.nextLine();

            if (idades[i] <= 16) {
                System.out.println("A idade precisa ser maior que 16, por favor, digite outro número.");
                i--;
                continue;
            }

            System.out.print("Digite o peso da pessoa: ");
            pesos[i] = sc.nextFloat();
            sc.nextLine();

            System.out.print("Digite a altura da pessoa: ");
            alturas[i] = sc.nextFloat();
            sc.nextLine();
        }
    }

    static void listarPessoas(String[] nomes, int[] idades, float[] alturas, float[] pesos) {
        if (idades[0] == 0) {
            System.out.print("\nErro, cadastre pessoas primeiro.\n");
        } else {
            for (int i = 0; i < NUMERO_DE_PESSOAS; i++) {
                System.out.printf("\n%s, %.2fKG, %.2fm, %d anos", nomes[i], pesos[i], alturas[i], idades[i]);
            }
            System.out.println();
        }
    }

    static void mediaDosDados(int[] idades, float[] alturas, float[] pesos) {
        if (idades[0] == 0) {
            System.out.print("\nErro, cadastre pessoas primeiro\n");

        } else {
            float mediaAux = 0f;

            for (int i : idades) {
                mediaAux += i;
            }
            System.out.print("\nMedia das idades: " + mediaAux / NUMERO_DE_PESSOAS);

            mediaAux = 0f;
            for (float i : pesos) {
                mediaAux += i;
            }
            System.out.print("\nMedia dos pesos: " + mediaAux / NUMERO_DE_PESSOAS);

            mediaAux = 0f;
            for (float i : alturas) {
                mediaAux += i;
            }
            System.out.print("\nMedia das alturas: " + mediaAux / NUMERO_DE_PESSOAS);

            mediaAux = 0f;
            for (int i = 0; i < 5; i++) {
                mediaAux += pesos[i] / (alturas[i] * alturas[i]);
            }
            System.out.println("\nMedia dos IMCs: " + mediaAux / NUMERO_DE_PESSOAS);

        }
    }

    static void IMC(String[] nomes, float[] alturas, float[] pesos, int[] idades) {
        if (idades[0] == 0) {
            System.out.print("\nErro, cadastre pessoas primeiro\n");
        } else {
            String classificacao;
            float imc;
            for (int i = 0; i < NUMERO_DE_PESSOAS; i++) {
                imc = pesos[i] / (alturas[i] * alturas[i]);
                if (imc < 18.5) {
                    classificacao = "abaixo do peso";
                } else if (imc < 24.9) {
                    classificacao = "peso ideal (parabéns)";
                } else if (imc < 29.9) {
                    classificacao = "levemente acima do peso";
                } else if (imc < 34.9) {
                    classificacao = "obesidade grau 1";
                } else if (imc < 39.9) {
                    classificacao = "obesidade grau 2 (severa)";
                } else {
                    classificacao = "obesidade 3 (mórbida)";
                }
                System.out.printf("\n%s, %.2f, %s\n", nomes[i], imc, classificacao);
            }
        }
    }

    static void valoresIdades(String[] nomes, int[] idades) {
        if (idades[0] == 0) {
            System.out.print("\nErro, cadastre pessoas primeiro\n");
        } else {
            int maior = 0, menor = 0;
            for (int i = 0; i < NUMERO_DE_PESSOAS; i++) {
                System.out.printf("%s: %d anos\n", nomes[i], idades[i]);
                if (idades[i] > idades[maior])
                    maior = i;
                if (idades[i] < idades[menor])
                    menor = i;
            }

            System.out.printf("\nA pessoa mais velha é: %s com %d anos\n", nomes[maior], idades[maior]);
            System.out.printf("A pessoa mais nova é: %s com %d anos\n", nomes[menor], idades[menor]);
        }
    }

    static void dadoDaPessoa(String[] nomes, int[] idades, float[] alturas, float[] pesos) {
        if (idades[0] == 0) {
            System.out.print("\nErro, cadastre pessoas primeiro\n");
        } else {
            String sobrenome;

            System.out.print("Digite o sobrenome da pessoa: ");
            sobrenome = sc.nextLine().trim();

            boolean sobrenomeNaoExiste = true;
            for (int i = 0; i < NUMERO_DE_PESSOAS; i++) {
                if (!(nomes[i].substring(nomes[i].indexOf(' ') + 1).equalsIgnoreCase(sobrenome)))
                    continue;

                System.out.printf("\nNome sobrenome: %s\n", nomes[i]);
                System.out.printf("Idade: %d\n", idades[i]);
                System.out.printf("Peso: %.2f\n", pesos[i]);
                System.out.printf("Altura: %.2f\n", alturas[i]);

                String classificacao;
                float imc;
                imc = pesos[i] / (alturas[i] * alturas[i]);

                if (imc < 18.5) {
                    classificacao = "abaixo do peso";
                } else if (imc < 24.9) {
                    classificacao = "peso ideal (parabéns)";
                } else if (imc < 29.9) {
                    classificacao = "levemente acima do peso";
                } else if (imc < 34.9) {
                    classificacao = "obesidade grau 1";
                } else if (imc < 39.9) {
                    classificacao = "obesidade grau 2 (severa)";
                } else {
                    classificacao = "obesidade 3 (mórbida)";
                }

                System.out.printf("Imc: %.2f\n", imc);
                System.out.printf("Classificação do IMC: %s\n", classificacao);
                sobrenomeNaoExiste = false;
            }

            if (sobrenomeNaoExiste)
                System.out.println("\nNão foi encontrado nenhuma pessoa com esse sobrenome\n");
        }
    }
}
