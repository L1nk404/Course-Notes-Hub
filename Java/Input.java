
import java.util.Scanner;

public class Input
{
    public static void main(String[] args)
    {
        // string input
        System.out.printf("Type your name: ");
        Scanner name_input = new Scanner(System.in);
        String name = name_input.nextLine().trim(); // trim to not store blank space before firts char



        // int input
        System.out.printf("Type your age: ");
        Scanner age_input = new Scanner(System.in);
        int age = age_input.nextInt();

        System.out.printf("Hello %s, you are %d years old\n", name, age);
    }
}
