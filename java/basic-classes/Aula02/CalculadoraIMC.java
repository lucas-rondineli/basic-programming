package Aula02;

import java.util.Scanner;

public class CalculadoraIMC {

    public static void main(String[] Args) {
        Scanner sc = new Scanner(System.in);

        float altura, peso, imc;
        System.out.print("Digite sua altura: ");
        altura = sc.nextFloat();
        System.out.print("Digite seu peso: ");
        peso = sc.nextFloat();

        imc = peso / (altura * altura);
        System.out.println(String.format("Seu IMC é: %.2f", imc));

        sc.close();
    }
}