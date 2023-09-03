package problem04;

import java.util.Scanner;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n, k, m, clockPos, antiPos;
        LinkedList<Integer> people;

        while (true) {
            n = sc.nextInt();
            k = sc.nextInt();
            m = sc.nextInt();
            if (n + m + k == 0)
                break;
            
            people = new LinkedList<Integer>();
            for (int i = 0; i < n; i++)
                people.add(i + 1);
            clockPos = 0;
            antiPos = n - 1;
            
            while (true) {
                clockPos = (clockPos + k - 1) % people.size();
                antiPos = ((antiPos - m + 1) % people.size() + people.size()) % people.size();
                
                if (clockPos == antiPos) {
                    System.out.printf("%3d", people.get(clockPos));
                    people.remove(clockPos);
                } else {
                    System.out.printf("%3d%3d", people.get(clockPos), people.get(antiPos));
                    people.remove(clockPos);
                    if (clockPos < antiPos) {
                        people.remove(--antiPos);
                    } else {
                        people.remove(antiPos);
                        clockPos--;
                    }
                }
                antiPos--;
                

                if (people.isEmpty())
                    break;
                System.out.printf(",");
            }
            System.out.println();
        }

        sc.close();
    }
}
