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
            case 1 -> System.out.printf("Sua nota foi Ruim\n");
            case 2 -> System.out.printf("Sua nota foi Regular\n");
            case 3 -> System.out.printf("Sua nota foi Boa\n");
            case 4 -> System.out.printf("Sua nota foi Muito Boa\n");
            case 5 -> System.out.printf("Sua nota foi Ótimo\n");
            
            default -> System.out.printf("Nota inválida!\n");                
        }
    }    
}
