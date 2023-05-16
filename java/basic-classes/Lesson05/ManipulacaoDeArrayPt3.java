package Lesson05;

import java.util.Arrays;
import java.util.Scanner;

public class ManipulacaoDeArrayPt3 {
    public static void main(String[] Args) {
        int[] numeros = new int[7];
        int total = 0;
        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < numeros.length; i++) {
            System.out.printf("Entre com o %do valor: ", i + 1);
            numeros[i] = sc.nextInt();
            total += numeros[i];
        }
        Arrays.sort(numeros);

        System.out.printf("\nA soma total foi de: %d\n", total);
        System.out.printf("O array de forma crescente é: %s", Arrays.toString(numeros));
        sc.close();
    }
}
