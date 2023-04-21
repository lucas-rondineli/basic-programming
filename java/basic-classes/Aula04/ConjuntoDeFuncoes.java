package Aula04;

import java.util.Scanner;
import javax.swing.JOptionPane;

public class ConjuntoDeFuncoes {
    public static void main(String[] Args) {
        pratica1();
        pratica2();
        pratica3();
        pratica4();
        pratica5();
        pratica6();
    }

    static void pratica1() {
        String pares = "";
        int nElementos = 0;
        for (int i = 150; i <= 300; i += 2)
            pares += ++nElementos % 10 != 0 ? String.format("%03d, ", i) : String.format("%03d\n", i);
        JOptionPane.showMessageDialog(null, pares, "Problema 1 - Pares entre 150 e 300", 1);
    }

    static void pratica2() {
        String multiplosDe3 = "";
        int nElementos = 0;
        for (int i = 3; i <= 100; i += 3)
            multiplosDe3 += ++nElementos % 10 != 0 ? String.format("%03d, ", i) : String.format("%03d\n", i);

        JOptionPane.showMessageDialog(null, multiplosDe3, "Problema 2 - Multiplos de 3", 1);
    }

    static void pratica3() {
        String fatoriais = "";
        int fact = 1;
        for (int i = 0; i < 10; i++) {
            fatoriais += String.format("%d! = %d\n", i + 1, fact);
            fact *= (i + 2);
        }
        JOptionPane.showMessageDialog(null, fatoriais, "Problema 3 - Fatoriais de 1 à 10", 1);
    }

    static void pratica4() {

        Scanner sc = new Scanner(System.in);

        float a, b, c;
        a = Integer.parseInt(JOptionPane.showInputDialog(null, "Entre com o tamanho do lado 1:",
                "Problema 4 - Tipo do Triângulo", 1));
        b = Integer.parseInt(JOptionPane.showInputDialog(null, "Entre com o tamanho do lado 2:",
                "Problema 4 - Tipo do Triângulo", 1));
        c = Integer.parseInt(JOptionPane.showInputDialog(null, "Entre com o tamanho do lado 3:",
                "Problema 4 - Tipo do Triângulo", 1));

        if (a >= (b + c) || b >= (a + c) || c >= (a + b))
            JOptionPane.showMessageDialog(null, "Não é um triângulo.", "Problema 4 - Tipo do Triângulo", 1);
        else if (a == b && b == c)
            JOptionPane.showMessageDialog(null, "É um triângulo equilátero.", "Problema 4 - Tipo do Triângulo", 1);
        else if (a == b || b == c || a == c)
            JOptionPane.showMessageDialog(null, "É um triângulo isóceles.", "Problema 4 - Tipo do Triângulo", 1);
        else
            JOptionPane.showMessageDialog(null, "É um triângulo escaleno.", "Problema 4 - Tipo do Triângulo", 1);
        sc.close();
    }

    static void pratica5() {
        float[] r = new float[4];
        r[0] = Float.parseFloat(
                JOptionPane.showInputDialog(null, "Entre com a primeira resistência:", "Problema 5 - Resistências", 1));
        r[1] = Float.parseFloat(
                JOptionPane.showInputDialog(null, "Entre com a segunda resistência:", "Problema 5 - Resistências", 1));
        r[2] = Float.parseFloat(
                JOptionPane.showInputDialog(null, "Entre com a terceira resistência:", "Problema 5 - Resistências", 1));
        r[3] = Float.parseFloat(
                JOptionPane.showInputDialog(null, "Entre com a quarta resistência:", "Problema 5 - Resistências", 1));

        int maior = 0, menor = 0;
        for (int i = 1; i < 4; i++) {
            if (r[i] > r[maior])
                maior = i;

            if (r[i] < r[menor])
                menor = i;
        }
        float rt = r[0] + r[1] + r[2] + r[3];
        JOptionPane.showMessageDialog(null, String.format(
                "Resistências - R1:%.2f, R2:%.2f, R3:%.2f, R4:%.2f\nMaior resistência - R%d: %.2f\nMenor resistência - R%d: %.2f\nTotal de resistência - RT:%.2f",
                r[0], r[1], r[2], r[3], maior, r[maior], menor, r[menor], rt),
                "Problema 5 - Resistências", 1);
    }

    static void pratica6() {
        char c;
        float temp;
        while (true) {
            temp = Float.parseFloat(JOptionPane.showInputDialog(null, "Entre com a temperatura em Celsius:",
                    "Problema 6 - Temperatura", 1));
            JOptionPane.showMessageDialog(null, String.format("%.2fC = %.2fF", temp, 9 * temp / 5 + 32),
                    "Problema 6 - Temperatura", 1);
            c = JOptionPane.showInputDialog(null, "Deseja continuar? [S/N]", "Problema 6 - Temperatura", 1)
                    .toLowerCase().charAt(0);
            if (c == 'n')
                break;
        }
    }
}
