import java.util.Scanner;
import java.util.Locale;

public class Aula02_ex003 {
    public static void main(String[] Args) {
        Locale.setDefault(Locale.US);
    }

    public static void printf() {
        System.out.printf("Menor Byte: %d\n", Byte.MIN_VALUE);
        System.out.printf("Maior Byte: %d\n", Byte.MAX_VALUE);
        System.out.printf("Menor Short Int: %d\n", Short.MIN_VALUE);
        System.out.printf("Maior Short Int: %d\n", Short.MAX_VALUE);
        System.out.printf("Menor Int: %d\n", Integer.MIN_VALUE);
        System.out.printf("Maior Int: %d\n", Integer.MAX_VALUE);
        System.out.printf("Menor Long: %d\n", Long.MIN_VALUE);
        System.out.printf("Maior Long: %d\n", Long.MAX_VALUE);
        System.out.printf("Menor Float: %.1E\n", Float.MIN_VALUE);
        System.out.printf("Maior Float: %.1E\n", Float.MAX_VALUE);
        System.out.printf("Menor Double: %.1E\n", Double.MIN_VALUE);
        System.out.printf("Maior Double: %.1E\n", Double.MAX_VALUE);
    }

    public static void leituraTiposConversoesIMC() {
        Scanner sc = new Scanner(System.in);

        float altura, peso, imc;
        // long teste1 = 1L;
        // float teste2 = 1.0F, teste3 = 2.3f;
        // final float pi = 3.14f;
        /*
         * isso funciona como
         * ex1 = 5;
         * printf(ex1 += 5);
         */

        // Conversão de tipos maiores para menores sempre dá erro caso não seja feito o
        // casting explícito

        // String x = "10";
        // int x = Integer.parseInt(x);
        // int x = 10;
        // String y = String.valueOf(x);

        System.out.print("Digite sua altura: ");
        altura = sc.nextFloat();
        System.out.print("Digite seu peso: ");
        peso = sc.nextFloat();

        imc = peso / (altura * altura);
        System.out.println(String.format("Seu IMC é: %.2f", imc));

        sc.close();
    }
}