package Aula08.Escritorio;

public class Teste {
    public static void main(String[] args) {
        Gerente gerente01 = new Gerente("Chefe", "001", 1000);
        Assistente assistente01 = new Assistente("Sr. Secretário", "002", 1000);
        Vendedor vendedor01 = new Vendedor("Lojista", "003", 1000, 10);

        System.out.printf("      Nome      | Matrícula | Salário Base | Salário Liquido\n");
        gerente01.mostreInfo();
        assistente01.mostreInfo();
        vendedor01.mostreInfo();
    }
}
