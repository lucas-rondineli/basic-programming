package Lesson05;

public class ManipulacaoDeStringPt1 {
    public static void main(String[] Args) {
        String nome = " Lucas", sobrenome = " Rondineli", nomeCompleto = nome + sobrenome, 
        primeiroNome = nomeCompleto.trim().substring(0, nomeCompleto.trim().indexOf(' '));

        System.out.println(nome);
        System.out.println(nomeCompleto);
        System.out.println(nomeCompleto.length());
        System.out.println(primeiroNome);

    }
}
