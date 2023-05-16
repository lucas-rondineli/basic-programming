package Lesson03;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class UsoDoBufferedReader {
    public static void main(String[] Args) {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        try {
            System.out.print("Entre com o valor do produto: ");
            double valor = Double.parseDouble(bf.readLine());
            System.out.print("Entre com a porcentagem de desconto: ");
            double desconto = Double.parseDouble(bf.readLine());
            System.out.printf("\nO desconto dado foi de: $%.2f\n", valor * (desconto / 100));
            System.out.printf("O novo valor do produto é: $%.2f", valor * (1 - desconto / 100));
        } catch (IOException erro) {
            System.out.printf("Houve um erro na entrada de dados: %s", erro.toString());
        } catch (NumberFormatException erro) {
            System.out.printf("Houve um erro na conversão, digite apenas caracteres numéricos: %s", erro.toString());
        }

    }
}
