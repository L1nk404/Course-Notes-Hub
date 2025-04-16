import java.util.List;

import pessoa.*;
import util.*;

public class App 
{
    public static void main(String[] args) throws Exception 
    {
        String filePath = "../data/pessoas.csv";

        List<Pessoa> pessoas = AcessoDados.loadPessoas(filePath);

        for(Pessoa pessoa: pessoas)
        {
            System.out.println(pessoa);
        }

        // Inserindo dados
        pessoas.add(new Pessoa("Rafael Ferreira", 15));
        pessoas.add(new Pessoa("Pedro Francisco", 9));

        // Lendo os dados
        AcessoDados.savePessoas(pessoas, filePath);

        System.out.printf("\nApós incluir mais duas pessoas:\n\n");
        
        AcessoDados.loadPessoas(filePath);

        for(Pessoa pessoa: pessoas)
        {
            System.out.println(pessoa);
        }
    }
}
