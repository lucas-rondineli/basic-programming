package list01;

import javax.swing.JOptionPane;

public class MesTraduzido {
    public static void main(String[] Args) {
        String[] mesPT = { "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro",
                "Outubro", "Novembro", "Dezembro" };
        String[] mesUS = { "January", "February", "March", "April", "May", "June", "July", "August", "September",
                "October", "November", "December" };
        int mes = 0, idioma = 0;
        char opt;

        do {
            while (true) {
                try {
                    mes = Integer.parseInt(
                            JOptionPane.showInputDialog(null, "Entre com um número entre 1 e 12:", "MesTraduzido", 3));
                    if (1 <= mes && mes <= 12)
                        break;
                    throw new NumberFormatException();
                } catch (NumberFormatException erro) {
                    JOptionPane.showMessageDialog(null, "Erro! Por favor, digite um número entre 1 e 12.",
                            "MesTraduzido",
                            0);
                }
            }

            while (true) {
                try {
                    idioma = Integer.parseInt(
                            JOptionPane.showInputDialog(null, "Entre com o idioma: (1 para português, 2 para inglês)",
                                    "MesTraduzido", 3));
                    if (idioma == 1 || idioma == 2)
                        break;
                    throw new NumberFormatException();
                } catch (NumberFormatException erro) {
                    JOptionPane.showMessageDialog(null,
                            "Erro! Por favor, digite apenas o número entre 1 para português ou 2 para inglês.",
                            "MesTraduzido",
                            0);
                }
            }

            JOptionPane.showMessageDialog(null, String.format("O mês %d em %s é: %s", mes,
                    idioma == 1 ? "Português" : "Inglês", idioma == 1 ? mesPT[mes - 1] : mesUS[mes - 1]),
                    "MesTraduzido", 1);

            while (true) {
                try {
                    opt = JOptionPane.showInputDialog(null, "Deseja continuar? [S/N]",
                            "MesTraduzido", 3).trim().toLowerCase().charAt(0);
                    if (opt == 's' || opt == 'n')
                        break;
                    throw new Exception();
                } catch (Exception erro) {
                    JOptionPane.showMessageDialog(null, "Erro! Por favor, digite apenas \"Sim\" ou \"Não\".",
                            "MesTraduzido",
                            0);
                }
            }
        } while (opt == 's');
    }
}
