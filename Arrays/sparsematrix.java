import java.util.*;
import java.io.*;
import java.lang.*;


public class sparsematrix {
    
    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);
        System.out.print("Enter the number of rows: ");
        int rows = console.nextInt();
        System.out.print("Enter the number of columns: ");
        int columns = console.nextInt();
        int[][] matrix = new int[rows][columns];
        System.out.println("Enter the matrix:");
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                matrix[i][j] = console.nextInt();
        System.out.println("The matrix is:");
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
                System.out.print(matrix[i][j] + " ");
            System.out.println();
        }
        int count = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                if (matrix[i][j] != 0)
                    count++;
        int[][] sparse = new int[count + 1][3];
        sparse[0][0] = rows;
        sparse[0][1] = columns;
        sparse[0][2] = count;
        int k = 1;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns; j++)
                if (matrix[i][j] != 0)
                {
                    sparse[k][0] = i;
                    sparse[k][1] = j;
                    sparse[k][2] = matrix[i][j];
                    k++;
                }
        System.out.println("The sparse matrix is:");
        for (int i = 0; i < count + 1; i++)
        {
            for (int j = 0; j < 3; j++)
                System.out.print(sparse[i][j] + " ");
            System.out.println();
        }
    }
}
