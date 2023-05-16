package List01;

import javax.swing.JOptionPane;
import java.util.Arrays;

public class Anagrama {
    public static void main(String[] Args) {
        String frase1 = JOptionPane.showInputDialog(null, "Entre com a primeira frase:", "Anagrama", 3).replace(" ", "")
                .toLowerCase();
        String frase2 = JOptionPane.showInputDialog(null, "Entre com a segunda frase:", "Anagrama", 3).replace(" ", "")
                .toLowerCase();
        char[] aux1 = frase1.toCharArray(), aux2 = frase2.toCharArray();
        Arrays.sort(aux1);
        Arrays.sort(aux2);

        if (Arrays.equals(aux1, aux2))
            JOptionPane.showMessageDialog(null, "A primeira frase É um anagrama da segunda.", "Anagrama", 1);
        else
            JOptionPane.showMessageDialog(null, "A primeira frase NÃO É um anagrama da segunda.", "Anagrama", 0);
    }
}
