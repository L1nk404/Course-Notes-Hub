package animais;

public class Ave extends Animal
{
    public Ave(String nome)
    {
        super(nome);
    }

    public void voar()
    {
        System.out.printf("O %s voou\n", getNome());
    }
}
