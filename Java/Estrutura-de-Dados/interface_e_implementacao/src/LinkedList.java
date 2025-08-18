import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

public class LinkedList 
{
        public static void hashSet() {
        System.out.println("[>>] HashSet; \n");
        // Criando conjunto
        Set<Integer> conjunto = new HashSet<>();

        System.out.printf("Tamanho Lista: %d\n", conjunto.size());
        
        conjunto.add(5);
        conjunto.add(3);
        conjunto.add(7);
        conjunto.add(3);
        conjunto.add(3);
        conjunto.add(5);
        conjunto.add(10);
        conjunto.add(0);
        
        System.out.printf("Tamanho Lista: %d\n", conjunto.size());

        System.out.printf("Lista [");
        for (Integer i : conjunto )
        {
            System.out.printf("%d ", i);
        }
        System.out.printf("]\n");
    }

    public static void treeSet()
    {
        System.out.println("\n\n[>>] TreeSet; \n");
        // Criando lista
        Set<Integer> conjunto = new TreeSet<>();

        System.out.printf("Tamanho Lista: %d\n", conjunto.size());
        
        conjunto.add(5);
        conjunto.add(3);
        conjunto.add(7);
        conjunto.add(3);
        conjunto.add(3);
        conjunto.add(5);
        conjunto.add(10);
        conjunto.add(0);
        
        System.out.printf("Tamanho Lista: %d\n", conjunto.size());

        System.out.printf("Lista [");
        for (Integer i : conjunto )
        {
            System.out.printf("%d ", i);
        }
        System.out.printf("]\n");
    }
    public static void main(String[] args) {
        hashSet();
        treeSet();
    }
}

