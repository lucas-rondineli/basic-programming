package Lesson07.Loja;

import java.util.Scanner;

public class Validador {
    private Scanner sc = new Scanner(System.in);

    public int lerInteiro(String msg, String erro) {
        int aux;
        while (true)
            try {
                System.out.printf(msg);
                aux = sc.nextInt();
                break;
            } catch (Exception e) {
                System.out.printf(erro);
                sc.nextLine();
            }
        sc.nextLine();
        return aux;
    }

    public double lerDouble(String msg, String erro) {
        double aux;
        while (true)
            try {
                System.out.printf(msg);
                aux = sc.nextDouble();
                break;
            } catch (Exception e) {
                System.out.printf(erro);
                sc.nextLine();
            }
        sc.nextLine();
        return aux;
    }

    public String lerString(String msg, String erro) {
        String aux;
        while (true)
            try {
                System.out.printf(msg);
                aux = sc.nextLine().strip();
                if (aux.length() == 0)
                    throw new Exception();
                break;
            } catch (Exception e) {
                System.out.printf(erro);
            }
        return aux;
    }
}
