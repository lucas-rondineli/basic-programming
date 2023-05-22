package lesson03;

import java.util.Scanner;

public class Futebol {
    public static void main(String[] Args) {
        Scanner sc = new Scanner(System.in);
        int n1, n2;

        System.out.print("Entre com a quantidade de pontos do líder do campeonato brasileiro de futebol: ");
        n1 = sc.nextInt();
        System.out.print("Entre com a quantidade de pontos do time lanterna: ");
        n2 = sc.nextInt();
        if (n1 == n2)
            System.out.print("\nO time lanterna já tem a mesma pontuação que o líder!");
        else {
            if (n1 < n2) {
                System.out.print("\nAs pontuações foram informadas em ordem invertida. Porém, de qualquer forma...");
                n1 = n1 + n2;
                n2 = n1 - n2;
                n1 = n1 - n2;
            }
            System.out.printf("\nO time lanterna precisa ganhar %d partida(s) para alcançar ou ultrapassar o outro.",
                    (int) Math.ceil((n1 - n2) / 3.0));
        }
        sc.close();
    }
}
