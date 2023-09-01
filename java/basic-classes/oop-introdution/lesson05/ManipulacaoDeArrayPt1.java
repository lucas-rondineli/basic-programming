package lesson05;

public class ManipulacaoDeArrayPt1 {
    public static void main(String[] Args) {
        int[] numeros = {10, 23, 45, 60, 5, 8, 23};
        int total = 0;

        for (int i : numeros)
            total += i;
        
            System.out.printf("A soma total foi de: %d", total);
    }
}
