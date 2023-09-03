package problem02;

import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            int n = sc.nextInt(), m = sc.nextInt(), value, nth;
            int[] data = new int[n];

            Map<Integer, ArrayList<Integer>> occurrenceMap = new HashMap<>();

            for (int i = 0; i < n; i++) {
                data[i] = sc.nextInt();
                if (!occurrenceMap.containsKey(data[i]))
                    occurrenceMap.put(data[i], new ArrayList<>());
                occurrenceMap.get(data[i]).add(i + 1);
            }

            for (int i = 0; i < m; i++) {
                nth = sc.nextInt();
                value = sc.nextInt();

                ArrayList<Integer> occurrences = occurrenceMap.get(value);

                if (occurrences != null && occurrences.size() >= nth)
                    System.out.println(occurrences.get(nth - 1));
                else
                    System.out.println(0);
            }
        }
        sc.close();
    }
}
