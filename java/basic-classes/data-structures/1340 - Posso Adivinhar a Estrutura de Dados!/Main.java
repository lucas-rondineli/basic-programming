import java.util.Scanner;
import java.util.Stack;
import java.util.LinkedList;
import java.util.Queue;
import java.util.PriorityQueue;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stack<Integer> stc = new Stack<Integer>();
        Queue<Integer> que = new LinkedList<Integer>();
        PriorityQueue<Integer> pque = new PriorityQueue<Integer>(Comparator.reverseOrder());
        int n, opt, x;
        boolean isStack, isQueue, isPqueue;

        while (sc.hasNext()) {
            n = sc.nextInt();
            stc.clear();
            que.clear();
            pque.clear();
            isStack = isQueue = isPqueue = true;
            for (int i = 0; i < n; i++) {
                opt = sc.nextInt();
                x = sc.nextInt();
                if (opt == 1) {
                    stc.push(x);
                    que.add(x);
                    pque.offer(x);
                } else {
                    if (stc.pop() != x && isStack)
                        isStack = false;
                    if (que.poll() != x && isQueue)
                        isQueue = false;
                    if (pque.poll() != x && isPqueue)
                        isPqueue = false;
                }
            }
            if (!isStack && !isQueue && !isPqueue)
                System.out.println("impossible");
            else if (isStack && !isQueue && !isPqueue)
                System.out.println("stack");
            else if (!isStack && isQueue && !isPqueue)
                System.out.println("queue");
            else if (!isStack && !isQueue && isPqueue)
                System.out.println("priority queue");
            else
                System.out.println("not sure");
        }

        sc.close();
    }
}
