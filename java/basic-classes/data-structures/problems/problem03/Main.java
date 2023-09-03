package problem03;

import java.util.Scanner;
import java.util.ArrayList;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> regions;
        LinkedList<Integer> aux;
        int n, m, removedElements, value, pos;

        while (true) {
            n = sc.nextInt();
            if (n == 0)
                break;

            regions = new ArrayList<Integer>(n);
            for (int i = 1; i <= n; i++)
                regions.add(i);

            m = 0;
            do {
                aux = new LinkedList<>(regions);
                pos = removedElements = 0;
                while (true) {
                    value = aux.get(pos);
                    if (value == 13)
                        break;
                    aux.remove(pos);
                    pos = (pos + m) % (n - ++removedElements);
                }
                m++;
            } while (removedElements != n - 1);

            System.out.println(m);
        }
        sc.close();
    }
}
