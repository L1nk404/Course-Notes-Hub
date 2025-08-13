package classes;

public class Pessoa 
{
    /* Modificadores de acesso: 

    • public: significa visibilidade total, ou seja, o atributo pode ser acessado
    dentro da própria classe e em qualquer outra classe, de qualquer pacote.

    • private: o elemento tem visibilidade somente dentro de sua própria classe.
    Outras classes não podem acessá-lo diretamente.

    • protected: permite que o atributo ou método seja visualizado na própria
    classe e em suas classes filhas (veremos em herança).

    • default: sem modificador de visibilidade. Permite o acesso das classes que
    estão no mesmo pacote.
    */

    // Para atributos, usamos usualmente o modificador Private - não podem ser lidos fora da classe
    
    // Atributos 
    private String nome;
    private int idade;
    private double altura;
    
    // Métodos
    
    // Construtor

    /* >> Construtor

    Um construtor é um método especial usado para inicializar um objeto ao ser criado.
    Ele é o primeiro método a ser executado assim que a classe é inicializada.
    O contrutor tem o mesmo nome da classe e não possui tipo de retorno (nem mesmo void).
    O construtor pode receber parâmetros para definir os valores iniciais dos atributos
    da classe, garantindo que o objeto seja criado em um estado válido.
    Construtores são chamados automaticamente quando um objeto é instanciado com "new".
    Exemplo: Pessoa(String nome, int idade, double altura)
    */
    // <modificador> <nomeDaClasse>
    public Pessoa()
    {
        System.out.println("O construtor está sendo executado assim que a classe foi inicializada!");
        
        // É útil para definirmos valores padrões para atributos
        altura = 1f;

        // Podemos usar para chamar outros métodos
        printGreetings();
    }

    /* >> Setter

    Um setter é um método público que permite modificar o valor de um atributo privado de uma classe.
    Ele segue o padrão "set" seguido do nome do atributo (ex: setNome() para o atributo "nome").
    O uso de setters é uma prática comum para garantir o encapsulamento, permitindo
    controle sobre como os dados são alterados, sem expor diretamente os atributos internos.
    void setNome(String nome)
    */

    public void setIdade(int idade) 
    {
        if (idade < 0)
        {
            System.out.println("Valor da idade não pode ser menor que 0! Valor inalterado.");
        }
        else
        {
            this.idade = idade;
        }
    }

    public void setAltura(double altura) 
    {
        if (altura < 0)
        {
            System.out.println("Valor da altura não pode ser menor que 0! Valor inalterado.");
        }
        else
        {
            this.altura = altura;
        }
    }

    public void setNome(String nome)
    {
        this.nome = nome; // altera nome
    }

    /* >> Getter 

    Um getter é um método público que permite acessar o valor de um atributo privado de uma classe.
    Ele segue o padrão "get" seguido do nome do atributo (ex: getNome() para o atributo "nome").
    O uso de getters é uma prática comum para garantir o encapsulamento, permitindo
    controle sobre como os dados são acessados, sem expor diretamente os atributos internos.
    String getNome()
    */

    // Damos visibilidade total para ser acessado em qualquer classe
    public String getNome()
    {
        return nome;
    }

    public int getIdade() 
    {
        return idade;
    }

    public double getAltura() 
    {
        return altura;
    }


    // Outros métodos
    private void printGreetings()
    {
        System.err.println("\nSaudações!\n");
    }
}
