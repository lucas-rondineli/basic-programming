package Aula05;

import javax.swing.JOptionPane;

public class ManipulacaoDeStringPt2 {
    public static void main(String[] Args) {
        String n = JOptionPane.showInputDialog(null, "Entre com seu nome completo:", "Prática 6.5", 1).trim();

        JOptionPane.showMessageDialog(null,
                String.format("Comprimento: %d\nPrimeira Letra: %c\nSobrenome: %s\nMaiúsculo: %s\nMinúsculo: %s",
                        n.length(),
                        n.charAt(0),
                        n.substring(n.indexOf(' ') + 1, n.indexOf(' ', n.indexOf(' ') + 1)),
                        n.toUpperCase(),
                        n.toLowerCase()),
                String.format("Informações sobre o nome: %s", n), 1);
    }
}

// Lucas/ /Rondineli Lucena Fragoso