import classes.Pessoa;

public class App 
{
    public static void main(String[] args) throws Exception 
    {
        
        // Criando um novo objeto
        Pessoa pessoa = new Pessoa();

        // Usando Setter para alterar uma variável privada na classe Pessoa
        pessoa.setNome("Bob Esponja");
        pessoa.setAltura(-1.62);
        pessoa.setIdade(23);

        // Usando getter para obter os valores
        System.out.println(pessoa.getNome());
        System.out.println(pessoa.getAltura());
        System.out.println(pessoa.getIdade());
    }
}
