package Lesson07.Empresa;

public class UsaEmpresa {
    public static void main(String[] Args) {
        Funcionario funcionario01 = new Funcionario("Fulano", 1000.00, 20220001);
        Gerente gerente01 = new Gerente("Chefe", 1000.00, 20220002);

        funcionario01.mostreInfo();
        System.out.println();
        gerente01.mostreInfo();
    }
}
