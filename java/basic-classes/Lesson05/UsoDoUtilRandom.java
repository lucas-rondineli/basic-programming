package Lesson05;

import java.util.Random;

public class UsoDoUtilRandom {
    public static void main(String[] Args) {
        Random gerador = new Random();
        int total = 0, aux;

        System.out.printf("Números sorteados:\n");
        for (int i = 0; i < 3; i++) {
            System.out.printf("%d\n", aux = gerador.nextInt(7));
            total += aux;
        }

        System.out.printf("Total = %d", total);
    }
}
