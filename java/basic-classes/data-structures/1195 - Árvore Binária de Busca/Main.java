import java.util.ArrayList;
import java.util.Scanner;

class Search_Binary_Tree {
    private SBTNode<Integer> root;
    private ArrayList<String> history;
    private int numberOfElements;

    public Search_Binary_Tree() {
        this.numberOfElements = 0;
        this.history = new ArrayList<String>();
        this.root = null;
    }

    public boolean isEmpty() {
        return this.numberOfElements == 0;
    }

    public int size() {
        return this.numberOfElements;
    }

    public SBTNode<Integer> root() {
        return this.root;
    }

    public ArrayList<String> getHistory() {
        return this.history;
    }

    public boolean search(int v) {
        this.history.clear();
        SBTNode<Integer> aux = this.root;

        while (aux != null) {
            this.history.add(Integer.toString(aux.getContent()));
            if (v == aux.getContent()) {
                return true;
            }

            if (v < aux.getContent()) {
                aux = aux.getLeft();
            } else {
                aux = aux.getRight();
            }
        }

        return false;
    }

    public void insert(int v) {
        if (search(v)) {
            return;
        }
        this.history.clear();

        SBTNode<Integer> newNode = new SBTNode<Integer>();
        newNode.setContent(v);

        if (isEmpty()) {
            this.root = newNode;
            this.numberOfElements++;
            return;
        }

        SBTNode<Integer> aux = this.root;

        privateInsert(newNode, aux);
        this.numberOfElements++;
    }

    private void privateInsert(SBTNode<Integer> node, SBTNode<Integer> aux) {
        this.history.add(Integer.toString(aux.getContent()));

        if (node.getContent().compareTo(aux.getContent()) < 0 && aux.getLeft() == null) {
            aux.setLeft(node);
            return;
        }

        if (node.getContent().compareTo(aux.getContent()) > 0 && aux.getRight() == null) {
            aux.setRight(node);
            return;
        }

        if (node.getContent().compareTo(aux.getContent()) < 0) {
            privateInsert(node, aux.getLeft());
        } else {
            privateInsert(node, aux.getRight());
        }
    }

    public int remove(int v) {
        this.history.clear();
        if (this.isEmpty())
            return 0;
        if (this.size() == 1) {
            int aux = this.root.getContent();
            this.root = null;
            this.numberOfElements--;
            return aux;
        }

        this.numberOfElements--;
        return remove(this.root, v).getContent();
    }

    private SBTNode<Integer> remove(SBTNode<Integer> node, int v) {
        if (node != null && node.getContent() != v)
            this.history.add(Integer.toString(node.getContent()));
        if (node == null)
            return null;
        else if (v < node.getContent())
            node.setLeft(remove(node.getLeft(), v));
        else if (v > node.getContent())
            node.setRight(remove(node.getRight(), v));
        else if (node.getRight() == null && node.getLeft() == null) {
            node = null;
            return node;
        } else if (node.getLeft() == null) {
            SBTNode<Integer> aux = node.getRight();
            if (this.root == node)
                this.root = aux;
            node = null;

            return aux;
        } else if (node.getRight() != null) {
            SBTNode<Integer> aux = findMin(node.getRight());
            remove(node, aux.getContent());
            node.setContent(aux.getContent());
        } else {
            SBTNode<Integer> aux = node.getLeft();
            if (this.root == node)
                this.root = aux;
            node = null;

            return aux;
        }
        return node;
    }

    private SBTNode<Integer> findMin(SBTNode<Integer> node) {
        if (node.getLeft() == null) {
            return node;
        }

        return findMin(node.getLeft());
    }

    public String preOrder_Traversal() {
        this.history.clear();
        ArrayList<String> aux = preOrder_Traversal(this.root);
        StringBuilder sb = new StringBuilder();
        for (String s : aux)
            sb.append(s).append(" ");
        sb.deleteCharAt(sb.length() - 1);
        return sb.toString();
    }

    private ArrayList<String> preOrder_Traversal(SBTNode<Integer> node) {
        if (node == null) {
            return this.history;
        }

        this.history.add(Integer.toString(node.getContent()));
        preOrder_Traversal(node.getLeft());
        preOrder_Traversal(node.getRight());

        return this.history;
    }

    public String postOrder_Traversal() {
        this.history.clear();
        ArrayList<String> aux = postOrder_Traversal(this.root);
        StringBuilder sb = new StringBuilder();
        for (String s : aux)
            sb.append(s).append(" ");
        sb.deleteCharAt(sb.length() - 1);
        return sb.toString();
    }

    private ArrayList<String> inOrder_Traversal(SBTNode<Integer> node) {
        if (node == null) {
            return this.history;
        }

        inOrder_Traversal(node.getLeft());
        this.history.add(Integer.toString(node.getContent()));
        inOrder_Traversal(node.getRight());

        return this.history;
    }

    public String inOrder_Traversal() {
        this.history.clear();
        ArrayList<String> aux = inOrder_Traversal(this.root);
        StringBuilder sb = new StringBuilder();
        for (String s : aux)
            sb.append(s).append(" ");
        sb.deleteCharAt(sb.length() - 1);
        return sb.toString();
    }

    private ArrayList<String> postOrder_Traversal(SBTNode<Integer> node) {
        if (node == null) {
            return this.history;
        }

        postOrder_Traversal(node.getLeft());
        postOrder_Traversal(node.getRight());
        this.history.add(Integer.toString(node.getContent()));

        return this.history;
    }

    public void clear() {
        this.history.clear();
        this.root = null;
        this.numberOfElements = 0;
    }
}

class SBTNode<T> {
    private T content;
    private SBTNode<T> left;
    private SBTNode<T> right;

    public SBTNode() {
        this.content = null;
        this.left = null;
        this.right = null;
    }

    public T getContent() {
        return this.content;
    }

    public SBTNode<T> getLeft() {
        return this.left;
    }

    public SBTNode<T> getRight() {
        return this.right;
    }

    public void setContent(T content) {
        this.content = content;
    }

    public void setLeft(SBTNode<T> left) {
        this.left = left;
    }

    public void setRight(SBTNode<T> right) {
        this.right = right;
    }
}

public class Main {
    public static void main(String[] Args) {
        Scanner sc = new Scanner(System.in);
        Search_Binary_Tree sbt = new Search_Binary_Tree();
        int c = sc.nextInt(), n;

        for (int i = 0; i < c; i++) {
            sbt.clear();
            n = sc.nextInt();
            for (int j = 0; j < n; j++)
                sbt.insert(sc.nextInt());

            System.out.printf("Case %d:\n", i + 1);
            System.out.printf("Pre.: %s\n", sbt.preOrder_Traversal());
            System.out.printf("In..: %s\n", sbt.inOrder_Traversal());
            System.out.printf("Post: %s\n\n", sbt.postOrder_Traversal());
        }
        sc.close();
    }
}
