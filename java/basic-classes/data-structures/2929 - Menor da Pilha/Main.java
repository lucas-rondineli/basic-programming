import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        LinkedList<Integer> stack = new LinkedList<>();
        StringBuilder answer = new StringBuilder();
        int min = Integer.MAX_VALUE;
        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            String[] input = br.readLine().split(" ");
            String command = input[0];

            if (command.equals("PUSH")) {
                int value = Integer.parseInt(input[1]);
                stack.push(value);
                if (value < min) min = value;
            } else if (stack.isEmpty()) {
                answer.append("EMPTY").append('\n');
            } else if (command.equals("POP")) {
                int value = stack.pop();
                if (value == min) {
                    min = Integer.MAX_VALUE;
                    for (int item : stack) {
                        if (item < min) min = item;
                    }
                }
            } else {
                answer.append(min).append('\n');
            }
        }

        System.out.print(answer.toString());
        br.close();
    }
}
