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
 * 
 *  >> Escrita
 * 
 * Aqui faremos o caminho contrário:
 * 
 *  - FileOutputStream: É um OuputStream e recebe um path para abrir um arquivo,
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

package util;

import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;

import pessoa.*;

public class AcessoDados {
    public static List<Pessoa> loadPessoas(String filePath)
    {
        List<Pessoa> pessoas = new ArrayList<>();

        try (
            InputStream iStream = new FileInputStream(filePath); 
            InputStreamReader iStreamReader = new InputStreamReader(iStream, StandardCharsets.UTF_8);
            ) {

            }
        catch (Exception e) {
            // TODO: handle exception
            }

        return pessoas;
    }
    
}
