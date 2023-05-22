package lesson05;

public class UsoDoMathRandom {
    public static void main(String[] Args) {
        String[] meses = { "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro",
                "Outubro", "Novembro", "Dezembro" };

        int n = (int) (Math.random() * 100) % 12;
        System.out.printf("O número sorteado foi: %d, que é %s", n, meses[n]);
    }
}
