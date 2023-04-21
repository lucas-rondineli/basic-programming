package Lista01;

import javax.swing.JOptionPane;

public class Calculadora {
    public static void main(String[] Args) {
        int opt, n;

        // Entrada da Operação
        while (true) {
            opt = entradaDaOperacao();
            if (opt == 0)
                break;
            n = entradaInteiro();

            switch (opt) {
                case 1:
                    dobro(n);
                    break;
                case 2:
                    triplo(n);
                    break;
                case 3:
                    metade(n);
                    break;
                case 4:
                    quadrado(n);
                    break;
                case 5:
                    cubo(n);
                    break;
                case 6:
                    raizQuadrada(n);
                    break;
                case 7:
                    raizCubica(n);
                    break;
                case 8:
                    modulo(n);
                    break;
                case 9:
                    inverso(n);
            }
        }
    }

    public static int entradaDaOperacao() {
        int n;
        while (true)
            try {
                n = Integer.parseInt(
                        JOptionPane.showInputDialog(null,
                                "Entre com a Operação:\n1 - Dobro\n2 - Triplo\n3 - Metade\n4 - Quadrado\n5 - Cubo\n6 - Raiz Quadrada\n7 - Raiz Cúbica\n8 - Módulo\n9 - Inverso\n0 - Sair do Programa",
                                "Calculadora", 3));
                if (0 <= n && n <= 9)
                    break;
                throw new NumberFormatException();
            } catch (NumberFormatException erro) {
                JOptionPane.showMessageDialog(null, "Por favor, digite apenas um dos valores citados.",
                        "Calculadora", 0);
            }
        return n;
    }

    public static int entradaInteiro() {
        int n;
        while (true)
            try {
                n = Integer.parseInt(
                        JOptionPane.showInputDialog(null, "Entre com um Valor Inteiro:", "Calculadora", 3));
                break;
            } catch (NumberFormatException erro) {
                JOptionPane.showMessageDialog(null, "Por favor, digite um inteiro válido.", "Calculadora", 0);
            }
        return n;
    }

    public static void dobro(int n) {
        JOptionPane.showMessageDialog(null, String.format("O Dobro de %d é: %d", n, n * 2), "Calculadora", 1);
    }

    public static void triplo(int n) {
        JOptionPane.showMessageDialog(null, String.format("O Triplo de %d é: %d", n, n * 3), "Calculadora", 1);
    }

    public static void metade(int n) {
        JOptionPane.showMessageDialog(null, String.format("A Metade de %d é: %.2f", n, n / 2f), "Calculadora", 1);
    }

    public static void quadrado(int n) {
        JOptionPane.showMessageDialog(null, String.format("O Quadrado de %d é: %d", n, n * n), "Calculadora", 1);
    }

    public static void cubo(int n) {
        JOptionPane.showMessageDialog(null, String.format("O Cubo de %d é: %d", n, n * n * n), "Calculadora", 1);
    }

    public static void raizQuadrada(int n) {
        JOptionPane.showMessageDialog(null, String.format("A Raiz Quadrada de %d é: %.2f", n, Math.sqrt(n)),
                "Calculadora", 1);
    }

    public static void raizCubica(int n) {
        JOptionPane.showMessageDialog(null, String.format("A Raiz Cúbica de %d é: %.2f", n, Math.cbrt(n)),
                "Calculadora", 1);
    }

    public static void modulo(int n) {
        JOptionPane.showMessageDialog(null, String.format("O Módulo de %d é: %d", n, n >= 0 ? n : -n), "Calculadora",
                1);
    }

    public static void inverso(int n) {
        JOptionPane.showMessageDialog(null, String.format("O Inverso de %d é: %d", n, -n), "Calculadora", 1);
    }
}
