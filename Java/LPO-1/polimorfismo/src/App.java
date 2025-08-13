import devflix.*;

public class App 
{
    /*
    Polimorfismo:
    
    Permite que vários métodos com mesmo nome, represente vários comportamentos diferentes
    */

    public static void main(String[] args) throws Exception {
        Filme filme = new Filme("Lagoa Azul");

        // Usando play()
        filme.play();

        // Usando play(audio)
        filme.play("Japonês");

        // Usando play(audio, legenda)
        filme.play("Inglês", "árabe");

        Serie serie = new Serie("Serie1", 10, 3, 4);

        System.out.println(serie);


    }
}
