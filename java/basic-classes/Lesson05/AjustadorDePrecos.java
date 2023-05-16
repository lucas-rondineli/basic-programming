package Lesson05;

import javax.swing.JOptionPane;

public class AjustadorDePrecos {
    public static void main(String[] Args) {
        float preco;
        preco = 0;

        while (true) {
            preco = Float.parseFloat(JOptionPane.showInputDialog(null, "Entre com o valor do produto: (0 para parar)", "Ajustador de Preços", 1));
            preco = Math.round(preco * 1.10f * 100) / 100.0f;
            if (preco == 0)
                break;
            JOptionPane.showMessageDialog(null, String.format("O novo preço será: $%f", preco), "Ajustador de Preços", 1);
        }
    }
}
