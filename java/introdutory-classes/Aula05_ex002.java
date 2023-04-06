import java.util.Scanner;

public class Aula05_ex002 {
    public static void main(String[] Args) {
        int[] numeros = new int[7];
        int total = 0;
        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < numeros.length; i++)
        {
            System.out.printf("Entre com o %do valor: ", i + 1);
            numeros[i] = sc.nextInt();
            total += numeros[i];
        }

        System.out.printf("A soma total foi de: %d", total);
        sc.close();
    }
}
