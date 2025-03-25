package animais;

public class Dragao extends Ave
{
    public Dragao(String nome)
    {
        super(nome);
    }

    public void soltar_fogo()
    {
        System.out.printf("O %s soltou fogo\n", getNome());
    }
}
