package Jogo;

/*
    • Classes abstratas são criadas quando não queremos que nenhum
      objeto seja criado a partir dela, ela somente servirá para ser
      herdada.

    • Classes abstratas podem ter métodos abstratos.
*/
public abstract class  Personagem 
{
    private String nome;
    private String classe;
    private int nivel;
    
    // Constructor -----------------------------------------
    public Personagem(String nome) 
    {
        this.nome = nome;
        this.classe = "Sem classe";
        this.nivel = 1;
    }


    /*
    Modificador sem acesso -> final, abstract

    O modificador sem acesso fica disposto entre o modificador de acesso e o tipo de retorno:

    <modificadorAcesso> <modificadorSemAcesso> <retornoMetodo> <nomeMetodo>

    - abstract: Apenas uma classe abstrata pode ter métodos abstratos. São métodos que não são 
                definidos, isto é, não possui corpo de intrução, somente a assinatura.
                Os métodos abstratos deverão, obrigatóriamente ser implementados nas subclasses que
                herdarem a classe abstrata.
    - final: final impede que o método seja sobrescrito, ou seja, não pode
             ser implementado em nenhuma classe herdada.
    */
    public abstract void atacarComArma();

    public final void atacar()
    {
        System.out.printf("%s atacou sem arma\n", nome);
    }

    @Override
    public String toString() 
    {
        String info = String.format(
            "%s (nível: %d) - Classe: %s", nome, nivel, classe);

        return info;
    }
   

    // Getter and Setter ----------------------------------
    public String getNome() {
        return nome;
    }


    public void setNome(String nome) {
        this.nome = nome;
    }


    public String getClasse() {
        return classe;
    }


    public void setClasse(String classe) {
        this.classe = classe;
    }


    public int getNivel() {
        return nivel;
    }


    public void setNivel(int nivel) {
        this.nivel = nivel;
    }    
}
