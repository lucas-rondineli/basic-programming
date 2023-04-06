import javax.swing.JOptionPane;

public class Aula02_ex005 {
    public static void main(String[] Args) {
        Double largura, comprimento, area, perimetro;

        largura = Double.parseDouble(JOptionPane.showInputDialog(null, "Entre com a largura:"));
        comprimento = Double.parseDouble(JOptionPane.showInputDialog(null, "Entre com o comprimento:"));

        area = largura * comprimento;
        perimetro = 2 * (largura + comprimento);

        JOptionPane.showMessageDialog(null, String.format("Área: %.2f, Perímetro: %.2f", area, perimetro));
    }
}
