import java.util.Scanner;

public class SwitchCase 
{
    public static void main(String[] args)
    {
        // Create a scanner object to read input
        Scanner scanner = new Scanner(System.in);  

        // Prompt user for input
        System.out.printf("Insira sua nota de 0 a 5: ");

        // Read the users input as integer
        int grade = scanner.nextInt();

        switch (grade) 
        {
            case 1:
                System.out.printf("Sua nota foi Ruim\n");                
                break;
            case 2:
                System.out.printf("Sua nota foi Regular\n");
                break;
            case 3:
                System.out.printf("Sua nota foi Boa\n");
                break;
            case 4:
                System.out.printf("Sua nota foi Muito Boa\n");
                break;
            case 5:
                System.out.printf("Sua nota foi Ótimo\n");
                break;
            
            default:
                System.out.printf("Nota inválida!\n");
                break;                
        }
    }    
}
