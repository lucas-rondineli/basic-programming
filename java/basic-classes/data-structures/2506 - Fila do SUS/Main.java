import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, h, m, c, tot, horarioAtendimento, limite;

        while (sc.hasNext()) {
            n = sc.nextInt();
            tot = 0;
            horarioAtendimento = 420;

            for (int i = 0; i < n; i++) {
                h = sc.nextInt();
                m = sc.nextInt();
                c = sc.nextInt();
                
                while (horarioAtendimento < h * 60 + m)
                    horarioAtendimento += 30;

                limite = h * 60 + m + c;
                if (horarioAtendimento > limite)
                    tot++;
                horarioAtendimento += 30;
                }

            System.out.println(tot);
        }

        sc.close();
    }
}
