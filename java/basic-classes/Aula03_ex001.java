import javax.swing.JOptionPane;

public class Aula03_ex001 {
    public static void main(String[] Args) {
        double[] gastos = { 15000, 23000, 17000 };
        double total = 0;
        for (double gasto : gastos) {
            total += gasto;
        }
        JOptionPane.showMessageDialog(null, String.format("Total gasto: $%.2f\nMédia em cada mês: %.2f", total, total / gastos.length));
    }
}
