package animais;

public class Animal 
{
    private String nome;

    // Constructor
    public Animal(String nome)
    {
        this.nome = nome;
    }
    
    // Métodos
    public void comer()
    {
        System.out.printf("%s comeu.\n", nome);
    }

    public void bebeu()
    {
        System.out.printf("%s bebeu.\n", nome);
    }


    // Getter
    public String getNome() {
        return nome;
    }   
}
