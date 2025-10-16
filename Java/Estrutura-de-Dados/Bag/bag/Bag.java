package bag;

public interface Bag extends Iterable<Integer> {

    static final int TAMANHO_MAX = 4;

    int size();

    void add(int e);
}