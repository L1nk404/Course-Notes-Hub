package Serie;

public class Serie 
{
    private String nome;
    private int temporadas;
    private int ano;

    // Construtctors
    public Serie(String nome, int temporadas, int ano) 
    {
        this.nome = nome;
        this.temporadas = temporadas;
        this.ano = ano;
    }


    // Métodos específicos da classe
    
    public String pegarInfo()
    {
        String info = String.format(
            "Print pelo método pegarInfo:\nNome %s (%d) - %d temporada(s).\n"
            , nome, ano, temporadas);

        return info;
    }

    @Override  // Sobrescreve um método em super
    public String toString() 
    {
        /*
        toString e outros métodos são herdados de uma classe Mãe chamada Object.
        */
        String info = String.format(
            "\nPrint pelo método pegar toString de forma implícita:\nNome %s (%d) - %d temporada(s).\n"
            , nome, ano, temporadas);

        return info;
    }


    // Getter and Setter
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getTemporadas() {
        return temporadas;
    }

    public void setTemporadas(int temporadas) {
        this.temporadas = temporadas;
    }

    public int getAno() {
        return ano;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }
    
}
