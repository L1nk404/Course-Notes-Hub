import implementacao.*;

public class App {
    public static void main(String[] args) throws Exception {
        MinhaPilha pilha = new MinhaPilha();

        System.out.println("Size:");
        System.out.println(pilha.size());

        System.out.println("Is empty?");
        System.out.println(pilha.isEmpty());

        pilha.push(1);
        pilha.push(2);
        pilha.push(3);
        pilha.push(4);

        System.out.println("\nSize:");
        System.out.println(pilha.size());

        System.out.println("\nPop");
        System.out.println(pilha.pop());
        System.out.println(pilha.pop());
        System.out.println(pilha.pop());
        System.out.println(pilha.pop());

        System.out.println("\nSize:");
        System.out.println(pilha.size());

        pilha.push(60);
        pilha.push(21);
        pilha.push(33);
        pilha.push(42);

        System.out.println("\nPeek");
        System.out.println(pilha.peek());
        System.out.println(pilha.peek());
        System.out.println(pilha.peek());
        System.out.println(pilha.peek());
        System.out.println(pilha.peek());

        System.out.println("\nSize:");
        System.out.println(pilha.size());

    }
}
