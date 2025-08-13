package animais;

public class Cachorro extends Animal
{
    // Precisamos chamar o construtor da classe super
    public Cachorro(String nome)
    {
        super(nome); // Estamos passando as variáveis para o construtor da classe mãe
    }    

    public void latir()
    {
        System.out.printf("%s latiu\n", getNome());
    }

    public void lamber()
    {
        System.out.printf("%s lambeu\n", getNome());
    }
}
