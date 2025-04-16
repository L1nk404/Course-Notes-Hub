package util;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;

import pessoa.*;

// Leitura de dados
public class AcessoDados {    
    
    @SuppressWarnings("CallToPrintStackTrace")
    public static List<Pessoa> loadPessoas(String filePath)
    {
        /*
        * >> Leitura
        * 
        * Aqui usaremos 3 classes:
        * 
        * - FileInputStream: Um InputStream que recebe o path e lê uma cadeia de
        *      de bytes.
        *  - InputStreamReader: Recebe um InputStream e uma codificação, usa esta
        *      codificação para transformar os bytes em caracteres.
        *  - BufferedReader: Recebe um InputStreamReader e é um facilitador, esta
        *      classe nos dá a possibilidade de ler cada linha de um arquivo, ou
        *      cada palavra. Sem ela teríamos que ler cada caratere
        */

        List<Pessoa> pessoas = new ArrayList<>();

        try 
        (
                InputStream iStream = new FileInputStream(filePath); 
                InputStreamReader iStreamReader = new InputStreamReader(iStream, StandardCharsets.UTF_8);
                BufferedReader bReader = new BufferedReader(iStreamReader);
        ) 
        {
            String linha;
            
            // Ler toda linha até linha ser nula
            while((linha = bReader.readLine()) != null)
            {                    
                /*
                * Vamos criar uma array de Strings, onde cada palavra separada por "," será 
                * convertido em um elemento da array.
                * 
                * O objetivo principal é usá-la para organizar os dados. Note que a mesma
                * será resetada a cada loop.
                * Assim, como estamos lendo um arquivo contendo apenas "<nome>, <idade>" 
                * por linha
                */
                
                String[] palavras = linha.split(",");
                
                // // Podemos printar as palavras usando for each
                // // para cada p(elemento) em palavras(array)

                // int i = 0;
                // System.out.printf("Linha %d\n", i++);
                // for(String p: palavras)
                // {
                //     System.out.printf("Palavra: %s\n", p);
                // }

                // Agora vamos organizar os dados
                String nome = palavras[0];
                int idade = Integer.parseInt(palavras[1]);

                // Criamos o objeto pessoa
                Pessoa pessoa = new Pessoa(nome, idade);

                // Finalmente adicionamos os dados na array
                pessoas.add(pessoa);
            }
        }
        catch (Exception e) 
        {
            e.printStackTrace();
        }

        return pessoas;
    }
    
    @SuppressWarnings("CallToPrintStackTrace")
    public static void savePessoas(List<Pessoa> pessoas, String filePath)
    {
        /*
        *  >> Escrita
        * 
        * Aqui faremos o caminho contrário:
        * 
        *  - FileutputStream: É um OuputStream e recebe um path para abrir um arquivo,
        *      - Usamos `new FileOutputStream(filePath);` para escrever do começo do 
        *          arquivo.
        *      - Para escrever no final do arquivo usamos como segundo argumento "true":
        *          `FileOutputStream(filePath, true);
        *  - OutputStreamWriter: Recebe um OutputStream e uma codificação, para saber em
        *      qual codificação está escrito.
        *  - PrintWriter: Recebe OutputStreamWriter, e será um facilitador para que possamos
        *      usar os métodos que já conhecemos, como o prinln
        * 
        *  OBS: um PrintWriter deve ser criado com `newPrintWriter(osw, true);`, sendo o 
        *      segundo argumento a opção de usar flush a cada comando.
        *      - Flush é o comando para que ele abra o arquivo, escreva e salbe o que foi
        *          escrito. Caso não seja usado, o arquivo não será salvo.
        */

        try
        ( 
            OutputStream oStream = new FileOutputStream(filePath);
            OutputStreamWriter oSWriter = new OutputStreamWriter(oStream, StandardCharsets.UTF_8);
            PrintWriter pWriter = new PrintWriter(oSWriter, true);                
        )
        {
            // Usamos o for each para iterar pela array e escrever os dados no arquivo .csv
            for(Pessoa pessoa : pessoas)
            {
                pWriter.printf("%s,%d\n", pessoa.getNome(), pessoa.getIdade());
            }
        } 
        catch (Exception e)
        {
            e.printStackTrace();
        }


    }
}
