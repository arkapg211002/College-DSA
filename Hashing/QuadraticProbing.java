/*
 * Quadratic probing implementation of hash tables.
 */

import java.util.*;
import java.io.*;
import java.lang.*;

public class QuadraticProbing {
    
    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);
        System.out.print("Enter the size of the hash table: ");
        int size = console.nextInt();
        int[] table = new int[size];
        for (int i = 0; i < size; i++)
            table[i] = -1;
        System.out.print("Enter the number of elements to be inserted: ");
        int n = console.nextInt();
        for (int i = 0; i < n; i++)
        {
            System.out.print("Enter the element to be inserted: ");
            int element = console.nextInt();
            int index = element % size;
            if (table[index] == -1)
                table[index] = element;
            else
            {
                int j = 1;
                while (j != size)
                {
                    int k = (index + j * j) % size;
                    if (table[k] == -1)
                    {
                        table[k] = element;
                        break;
                    }
                    j++;
                }
                if (j == size)
                    System.out.println("The table is full.");
            }
        }
        System.out.println("The hash table is:");
        for (int i = 0; i < size; i++)
            System.out.println(i + " " + table[i]);
    }
}
