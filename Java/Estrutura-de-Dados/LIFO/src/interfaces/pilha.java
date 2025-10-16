package interfaces;

public interface pilha {

    boolean isEmpty(); // verirfica se está vazia

    int size(); // tamanho

    void push(int e); // coloca elementos

    int pop(); // retorna e apaga o próximo

    int peek(); // retorna o próximo (sem apagar)

}
