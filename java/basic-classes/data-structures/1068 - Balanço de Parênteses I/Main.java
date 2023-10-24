import java.util.EmptyStackException;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stack<Character> stc = new Stack<Character>();
        String expression;
        int expLen;
        char aux;
        boolean sucess;

        while (sc.hasNext()) {
            expression = sc.next();
            expLen = expression.length();
            sucess = false;
            try {
                for (int i = 0; i < expLen; i++) {
                    aux = expression.charAt(i);
                    if (aux == '(')
                        stc.push(aux);
                    else if (aux == ')')
                        stc.pop();                    
                }

                if (stc.size() != 0)
                    throw new EmptyStackException();

                sucess = true;
            } catch (EmptyStackException e) {
                System.out.println("incorrect");
                stc.clear();
            }

            if (sucess)
                System.out.println("correct");
        }

        sc.close();
    }
}
