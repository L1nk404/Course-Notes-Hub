package devflix;

public class Serie extends Filme {
    private int temporadas;
    private int temporadaAtual;
    private int episodiosTemporada;
    private int episodioAtual;
    
    public Serie(String nome, int temporadas, int episodiosTemporada, int episodioAtual) {
        super(nome);
        this.temporadas = temporadas;
        this.temporadaAtual = 1;
        this.episodiosTemporada = episodiosTemporada;
        this.episodioAtual = 1;
    }

    // Os métodos específicos da classe
    @Override
    public String toString() {
        String informacao = String.format("Serie %s Temp %dx%d Ep.(audio %s, legenda %s)",
         getNome(),
         temporadaAtual,
         episodioAtual,
         getAudio(),
         getLegenda());


        return  informacao;
    }

    // Getters and Setters
    public int getTemporadas() {
        return temporadas;
    }

    public void setTemporadas(int temporadas) {
        this.temporadas = temporadas;
    }

    public int getTemporadaAtual() {
        return temporadaAtual;
    }

    public void setTemporadaAtual(int temporadaAtual) {
        this.temporadaAtual = temporadaAtual;
    }

    public int getEpisodiosTemporada() {
        return episodiosTemporada;
    }

    public void setEpisodiosTemporada(int episodiosTemporada) {
        this.episodiosTemporada = episodiosTemporada;
    }

    public int getEpisodioAtual() {
        return episodioAtual;
    }

    public void setEpisodioAtual(int episodioAtual) {
        this.episodioAtual = episodioAtual;
    }

    
}
