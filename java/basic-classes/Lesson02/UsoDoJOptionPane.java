package Lesson02;

import javax.swing.JOptionPane;

public class UsoDoJOptionPane {
    public static void main(String[] Args) {
        Double largura, comprimento, area, perimetro;

        largura = Double.parseDouble(JOptionPane.showInputDialog(null, "Entre com a largura:", "Área e Perímetro", 3));
        comprimento = Double.parseDouble(JOptionPane.showInputDialog(null, "Entre com o comprimento:", "Área e Perímetro", 3));

        area = largura * comprimento;
        perimetro = 2 * (largura + comprimento);

        JOptionPane.showMessageDialog(null, String.format("Área: %.2f, Perímetro: %.2f", area, perimetro), "Área e Perímetro", 1);
    }
}
