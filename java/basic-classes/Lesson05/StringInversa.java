package Lesson05;

import java.util.Scanner;

public class StringInversa {
    public static void main(String[] Args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.printf("Entre com a frase: ");
        StringBuilder frase = new StringBuilder();
        frase.append(sc.nextLine().replace(" ", "")).reverse();

        System.out.print(frase);

        sc.close();
    }
}
