
import javax.swing.JOptionPane;

public class input2 
{
    public static void main(String[] args)
    {
        
    
    double comprimento;
    
    comprimento = Double.parseDouble(JOptionPane.showInputDialog("Essa é a mensagem"));
    
    JOptionPane.showMessageDialog(null, "Bom dia , o numero é  %d");
    }
}
