
import java.util.Arrays;
import javax.swing.JOptionPane;

public class matrix
{
    public static void main(String [] args)
    {
        // array 1x5
        int[] numbersArray = new int[5];

        // Filling the array
        for (int i = 0; i < numbersArray.length; i ++ )
        {
            numbersArray[i] = Integer.parseInt(
                JOptionPane.showInputDialog(
                    "Digite o elemento " + (i + 1) + " da matriz." ));
        }

        // Using array method to print out:
        String array2string = Arrays.toString(numbersArray);

        JOptionPane.showMessageDialog(null, "A array 5x1 é " + array2string);

        // Matrix ================================================
               
        int [][] numbersMatrix = new int[3][2];

        // Filling the matrix
        for (int i = 0; i < 3; i ++ ) // rows
        {
            for (int j = 0; j < 2; j ++) // columns
            {
                numbersMatrix[i][j] = Integer.parseInt(
                    JOptionPane.showInputDialog(
                        "Digite o elemento " + "["+(i + 1)+"]"+"["+(j+1)+"]" + " da matriz." ));
            }
        }

        String matrix2string = Arrays.deepToString(numbersMatrix);

        JOptionPane.showMessageDialog(null, "A matriz 3x2 é " + matrix2string);
    }
}