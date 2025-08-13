package devflix;

public class Filme extends Video 
{
    private String audio;
    private String legenda;

    public Filme(String nome) {
        super(nome);
        this.audio = "Português";
        this.legenda = "Nenhuma";
    }


    // Polimorfismo por sobrescrista (Override)
    @Override
    public void play() {
        System.out.printf("Play: filme %s\n", getNome());
    }

    // Polimorfismo por sobrecarga (Overload)
    // -> alteramos a assinatura do método (colocamos um parâmetro diferente)

    /*
     * Assinatura de método:
     *  
     * <nome-do-método>(parâmetros)
     * 
     * Exemplo:
     *            Syntax                     -> Forma interpretada pelo java
     * - void play(String arg1)              -> play(String)
     * - void play(String arg2, String arg3) -> play(String, String)
     * - void play(String arg4, String arg5) -> play(String, String)
     */
    public void play(String audio)
    {
        this.audio = audio;
        
        if ("português".equals(audio)) {
            this.legenda = "nenhuma";
        } else {
            this.legenda = "português";
        }
        
        System.out.printf("Play: %s\n", toString());
    }

    public void play(String audio, String legenda) 
    {
        this.audio = audio;
        this.legenda = legenda;
        System.out.printf("Play: %s\n", toString());
    }

    @Override
    public String toString() {
        String informacao = String.format("Filme %s (audio %s, legenda %s)",
         getNome(), audio, legenda);
        return  informacao;
    }


    public String getAudio() {
        return audio;
    }


    public String getLegenda() {
        return legenda;
    }
}
