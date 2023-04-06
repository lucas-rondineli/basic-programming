import javax.swing.JOptionPane;
import java.util.Arrays;

public class Aula05_ex006 {
    public static void main(String[] Args) {
        float[] notas = new float[5];
        float total = 0;

        for (int i = 0; i < notas.length; i++) {
            notas[i] = Float.parseFloat(JOptionPane.showInputDialog(null, String.format("Entre com a %do nota:", i + 1),
                    "Entrada de Notas", 1));
            total += notas[i];
        }
        Arrays.sort(notas);
        JOptionPane.showMessageDialog(null,
                String.format("Notas Ordenadas: %s\nMédia Aritmética: %.2f", Arrays.toString(notas), total / notas.length), "Dados das Notas", 1);
    }
}
