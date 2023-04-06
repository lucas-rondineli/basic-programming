import java.util.Scanner;

public class Aula05_ex010 {
    public static void main(String[] Args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.printf("Entre com a frase: ");
        StringBuilder frase = new StringBuilder();
        frase.append(sc.nextLine().replace(" ", "")).reverse();

        System.out.print(frase);

        sc.close();
    }
}
