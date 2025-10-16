package implementacao;

import interfaces.*;

public class MinhaPilha implements pilha {

    int current_index = 0; // tamanho
    int array[] = new int[4];

    @Override
    public boolean isEmpty() {
        return current_index == 0;
    }

    @Override
    public int size() {
        return current_index;
    }

    @Override
    public void push(int e) {
        if (current_index == 4) {
            System.out.println("Tamanho máximo!");
            return;
        }

        array[current_index] = e;
        current_index++;
    }

    @Override
    public int pop() {
        current_index--;
        return array[current_index];
    }

    @Override
    public int peek() {
        return array[current_index - 1];
    }

}
