package animais;

public class Pombo extends Ave
{
    private int cartasEnviadas;

    public Pombo(String nome)
    {
        super(nome);
        cartasEnviadas = 10; // valor default
    }

    public void enviarCarta()
    {
        System.out.printf("O %s enviou %d carta\n", getNome(), cartasEnviadas);
        cartasEnviadas ++;
    }

    // Getter
    public int getCartasEnviadas() {
        return cartasEnviadas;
    }    
}
