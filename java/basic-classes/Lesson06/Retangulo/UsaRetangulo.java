package Lesson06.Retangulo;

import java.util.Scanner;

public class UsaRetangulo {
    public static void main(String[] Args) {
        Scanner sc = new Scanner(System.in);

        System.out.printf("Entre a largura e altura do retângulo: ");
        double largura = sc.nextDouble();
        double altura = sc.nextDouble();
        
        Retangulo x = new Retangulo(largura, altura);

        System.out.printf("Area = %.2f\n", x.area());
        System.out.printf("Perimetro = %.2f\n", x.perimetro());
        System.out.printf("Diagonal = %.2f\n", x.diagonal());
        sc.close();
    }
}
