package Jogo;

public final class Arqueiro extends Personagem
{  
    private String arma;

    public Arqueiro(String nome) 
    {
        super(nome);
        setClasse("Arqueiro");
        this.arma = "Arco Longo";
    }

    @Override
    public String toString() 
    {
        String infoPersonagem = super.toString(); // Herda as informações do método da classe herdada
        String infoArqueiro = String.format(" - Arma: %s", arma);

        // Retorna string concatenada
        return infoPersonagem + infoArqueiro;
    }

    @Override
    public void atacarComArma() 
    {
        System.out.printf("%s atacou com %s\n", getNome(), arma);    
    }
  
    
}
