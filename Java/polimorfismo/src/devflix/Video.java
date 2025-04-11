package devflix;

public class Video {
    private String nome;

    // Constructor
    public Video(String nome) {
        this.nome = nome;
    }


    public void play()
    {
        System.out.printf("Play: video qualquer\n");
    }


    public String getNome() {
        return nome;
    }


    public void setNome(String nome) {
        this.nome = nome;
    }

    
}
