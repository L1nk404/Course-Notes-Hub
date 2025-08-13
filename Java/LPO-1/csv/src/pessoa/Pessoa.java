package pessoa;

public class Pessoa {
    private String nome;
    private int idade;

    // Contructor
    public Pessoa(String nome, int idade) {
        this.nome = nome;
        this.idade = idade;
    }

    // -------------------------------------------------------------------------
    @Override
    public String toString() {
        String string = String.format("Nome: %s | idade: %d", nome, idade );
        return string;
    }


    // Getter and Setters -------------------------------------------------------
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    
    
    
}
