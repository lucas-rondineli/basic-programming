package problem01;

import java.util.Scanner;

class SeqList {
    private int[] data;
    private int numberOfElements;
    private int maxElements;

    public SeqList() {
        this.data = new int[5];
        this.numberOfElements = 0;
        this.maxElements = 5;
    }

    public SeqList(int size) {
        if (size > 0) {
            this.data = new int[size];
            this.numberOfElements = 0;
            this.maxElements = size;
        } else {
            System.out.printf("Tamanho inválido.\nCriando lista com tamanho 5.");
            this.data = new int[5];
            this.numberOfElements = 0;
            this.maxElements = 5;
        }
    }

    public boolean isEmpty() {
        if (this.numberOfElements == 0)
            return true;
        return false;
    }

    public boolean isFull() {
        if (this.numberOfElements == this.maxElements)
            return true;
        return false;
    }

    public int size() {
        return this.numberOfElements;
    }

    public int get(int index) {
        if (0 <= index && index < this.numberOfElements)
            return this.data[index];
        return -1;
    }

    public int indexOf(int v) {
        for (int i = 0; i < this.numberOfElements; i++)
            if (this.data[i] == v)
                return i;
        return -1;
    }

    public int indexOf(int v, int offset) {
        if (offset < 0 || offset >= this.numberOfElements)
            return -1;

        for (int i = offset; i < this.numberOfElements; i++)
            if (this.data[i] == v)
                return i;
        return -1;
    }

    public int indexOf(int v, int offset, int targethOccurrence) {
        if (offset < 0 || offset >= this.numberOfElements || targethOccurrence > this.maxElements)
            return -1;

        int numberOfOccurrences = 0;
        for (int i = offset; i < this.numberOfElements; i++)
            if (this.data[i] == v) {
                numberOfOccurrences++;
                if (numberOfOccurrences == targethOccurrence)
                    return i;
            }

        return -1;
    }

    public boolean insert(int v, int index) {
        if (index < 0 || index > this.numberOfElements || this.isFull())
            return false;

        for (int i = this.numberOfElements - 1; i >= index; i--)
            this.data[i + 1] = this.data[i];

        this.data[index] = v;
        this.numberOfElements++;
        return true;
    }

    public int remove(int index) {
        if (index < 0 || index >= this.numberOfElements)
            return -1;

        int removedElement = this.data[index];

        for (int i = index; i < this.numberOfElements - 1; i++)
            this.data[i] = this.data[i + 1];

        this.numberOfElements--;
        return removedElement;
    }

    public void clear() {
        if (this.numberOfElements > 0)
            for (int i = this.numberOfElements - 1; i >= 0; i--)
                this.remove(i);
    }

    public String toString() {
        if (this.numberOfElements == 0)
            return "[]";

        StringBuilder sb = new StringBuilder();
        sb.append('[');

        for (int i = 0; i < this.numberOfElements - 1; i++) {
            sb.append(this.data[i]);
            sb.append(", ");
        }
        sb.append(this.data[this.numberOfElements - 1]);
        return sb.append(']').toString();
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        SeqList evenList = new SeqList();
        SeqList oddList = new SeqList();
        SeqList[] lists = { evenList, oddList };

        int aux = 0;
        int selectedList;
        String word;
        for (int i = 0; i < 15; i++) {
            aux = sc.nextInt();
            sc.nextLine();

            selectedList = (aux & 1);

            lists[selectedList].insert(aux, lists[selectedList].size());

            if (lists[selectedList].isFull()) {
                word = selectedList == 0 ? "par" : "impar";
                for (int j = 0; j < 5; j++)
                    System.out.printf("%s[%d] = %d\n", word, j, lists[selectedList].get(j));
                lists[selectedList].clear();
            }
        }

        if (oddList.size() != 0)
            for (int i = 0; i < oddList.size(); i++)
                System.out.printf("impar[%d] = %d\n", i, oddList.get(i));

        if (evenList.size() != 0)
            for (int i = 0; i < evenList.size(); i++)
                System.out.printf("par[%d] = %d\n", i, evenList.get(i));

        sc.close();
    }
}
