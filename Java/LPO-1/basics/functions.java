import java.util.Scanner;
import javax.swing.JOptionPane;

public class functions 
{
    
    public static int pow(int num, int pow)
    {
        if (pow == 1)
        {
            return num;
        }
        return num * pow(num, pow - 1);
    }
    
    // Main <<
    public static void main(String[] args)
    {
        // Create scanner object
        Scanner scanner = new Scanner(System.in);

        int numberPow;

        System.out.printf("Enter a int: ");
        int number = scanner.nextByte();
       
        numberPow = pow(number, 3);

        // Output
        JOptionPane.showMessageDialog(null, number + "^3 = " + numberPow);
    }
}
