import bag.*;

public class app {

    public static void main(String[] args) {

        Bag bag = new MyBag();

        System.out.println("\nImprimindo a lista");
        System.out.println(bag);

        System.out.println("\nImprimindo tamanho");
        System.out.println(bag.size());

        System.out.println("\nAdicionando elemento");
        bag.add(5);

        System.out.println("\nImprimindo a lista");
        System.out.println(bag);

        System.out.println("\nImprimindo tamanho");
        System.out.println(bag.size());

        System.out.println("\nAdicionando elemento");
        bag.add(3);
        bag.add(7);
        bag.add(0);
        bag.add(1);
        bag.add(9);
        bag.add(4);

        System.out.println("\nImprimindo tamanho");
        System.out.println(bag.size());

        System.out.println("\nImprimindo a lista");
        System.out.println(bag);

        System.out.println("\nIterando sobre a bag:");
        for (int e : bag)
            System.out.println(e);

    }
}
