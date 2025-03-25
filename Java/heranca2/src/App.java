import Serie.*;
import Jogo.*;
import Util.*;

public class App 
{
    public static void main(String[] args) throws Exception 
    {
        ClearScreen.clearScreen();
        
        Serie serieQualquer = new Serie("The Last of Us", 1, 2023);

        System.out.printf("%s", serieQualquer.pegarInfo());

        // Note que podemos chamar o método toString implicitamente apenas chamando a classe
        System.out.printf("%s", serieQualquer); // Chama toString

        System.out.printf("\n----------------------------------\n");
        // ------------------------------------------------------------

        Arqueiro arqueiro = new Arqueiro("Legolas");
        System.out.println(arqueiro);
        arqueiro.atacar();
        arqueiro.atacarComArma();
    }
}