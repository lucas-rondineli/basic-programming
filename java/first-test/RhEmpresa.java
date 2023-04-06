import javax.swing.JOptionPane;
import java.io.IOException;

public class RhEmpresa {
    public static void main(String[] Args) {
        int n;

        // Entrada do Número de Funcionários
        while (true)
            try {
                n = Integer.parseInt(
                        JOptionPane.showInputDialog(null, "Entre com o número de funcionários: (Entre 0 e 40)",
                                "RhEmpresa", 3));
                if (0 < n && n < 40)
                    break;
                throw new NumberFormatException();
            } catch (NumberFormatException erro) {
                JOptionPane.showMessageDialog(null, "Por favor, digite apenas um número maior que 0 e menor que 40.",
                        "RhEmpresa", 0);
            }

        // Entrada do Nome e Salário dos Funcionários
        String[] nome = new String[n];
        float[] salario = new float[n];
        float maior = 0f, total = 0f, media = 0f;

        for (int i = 0; i < n; i++) {
            while (true)
                // Recebe o Nome do Funcionário
                try {
                    nome[i] = JOptionPane.showInputDialog(null,
                            String.format("Entre com o nome do %do funcionario:", i + 1), "RhEmpresa", 3).strip();
                    if (nome[i].length() != 0)
                        break;
                    throw new IOException("Por favor, digite um nome válido.");
                } catch (IOException erro) {
                    JOptionPane.showMessageDialog(null, String.format("Um erro ocorreu: %s", erro.getMessage()),
                            "RhEmpresa", 0);
                }

            while (true)
                // Recebe o Salário do Funcionário
                try {
                    salario[i] = Float.parseFloat(JOptionPane.showInputDialog(null,
                            String.format("Entre com o salário do %do funcionário:", i + 1), "RhEmpresa", 3));
                    if (salario[i] > 0)
                        break;
                    throw new NumberFormatException();
                } catch (NumberFormatException erro) {
                    JOptionPane.showMessageDialog(null, "Por favor, digite um salário válido.", "RhEmpresa", 0);
                }
            if (salario[i] > maior)
                maior = salario[i];
            total += salario[i];
        }
        media = total / n;

        // Mostrando o Maior Salário e a Média Salarial
        JOptionPane.showMessageDialog(null, String.format("Maior Salário: $%.2f\nMédia Salarial: $%.2f", maior, media),
                "RhEmpresa", 1);

        // Mostrando os Nomes como pedido
        StringBuilder igualMaior = new StringBuilder("Pessoas com o salário igual ao maior:\n");
        StringBuilder menorMedia = new StringBuilder("Pessoas com o salário menor que a média:\n");

        for (int i = 0; i < n; i++) {
            if (salario[i] == maior)
                igualMaior.append(String.format("%s\n", nome[i]));
            if (salario[i] < media)
                menorMedia.append(String.format("%s\n", nome[i]));
        }
        JOptionPane.showMessageDialog(null, igualMaior, "RhEmpresa", 1);
        JOptionPane.showMessageDialog(null, menorMedia, "RhEmpresa", 1);
    }
}
