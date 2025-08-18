
import java.util.ArrayList;
import java.util.List;

public class lista {
    
    public static void main(String[] args) {
        // Criando lista
        List <Integer> list = new ArrayList<>();

        System.out.printf("Tamanho Lista: %d\n", list.size());
        
        list.add(5);
        list.add(3);
        list.add(7);
        list.add(3);
        list.add(3);
        list.add(5);
        list.add(10);
        list.add(0);
        
        System.out.printf("Tamanho Lista: %d\n", list.size());

        System.out.printf("Lista [");
        for (int i = 0; i < list.size(); i ++)
        {
            System.out.printf("%d ", list.get(i));
        }
        System.out.printf("]\n");
    }
}

