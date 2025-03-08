import java.util.Scanner;

public class Conditional 
{
    @SuppressWarnings("ConvertToTryWithResources")
    public static void main(String[] args)
    {
        double IMC = 0.0f;

        // Create scanner obj
        Scanner scanner = new Scanner(System.in); 

        System.out.printf("Digite sua altura: ");
        float height = scanner.nextFloat();
        scanner.nextLine();  // Consume the leftover newline

        System.out.printf("Digite seu sexo [M/F]: ");
        String sex_string = scanner.nextLine().trim();

        // Extract the frist character
        char sex = sex_string.charAt(0);

        if (sex == 'm' || sex == 'M')
        {
            IMC = (72.7 * height) - 58; 
        }
        else if (sex == 'f' || sex == 'F')
        {
            IMC = (62.1 * height) - 44.7;
        }
        else
        {
            System.out.printf("Sexo Inválido\n");
            
            System.exit(-1); // close 
        }

        System.out.printf("IMC: %.2f\n", IMC);
        
        // Close the scanner
        scanner.close();
    }
    
}
