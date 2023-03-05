/*
 * This program implements a hash table using linear probing.
 */

import java.util.*;
import java.io.*;
import java.lang.*;

public class LinearProbing {
    
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
                int j = index + 1;
                while (j != index)
                {
                    if (j == size)
                        j = 0;
                    if (table[j] == -1)
                    {
                        table[j] = element;
                        break;
                    }
                    j++;
                }
                if (j == index)
                    System.out.println("The table is full.");
            }
        }
        System.out.println("The hash table is:");
        for (int i = 0; i < size; i++)
            System.out.println(i + " " + table[i]);
    }
}
