/*
 * Count Sort
 */
import java.util.*;
import java.io.*;
import java.lang.*;

public class CountSort {
    
    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);
        System.out.print("Enter the number of elements in the array: ");
        int n = console.nextInt();
        int[] array = new int[n];
        System.out.println("Enter the elements of the array: ");
        for (int i = 0; i < n; i++)
            array[i] = console.nextInt();
        countSort(array);
        System.out.println("The sorted array is: ");
        for (int i = 0; i < n; i++)
            System.out.print(array[i] + " ");
    }
    
    public static void countSort(int[] array)
    {
        int max = array[0];
        for (int i = 1; i < array.length; i++)
        {
            if (array[i] > max)
                max = array[i];
        }
        int[] count = new int[max + 1];
        for (int i = 0; i < array.length; i++)
        {
            count[array[i]]++;
        }
        int index = 0;
        for (int i = 0; i < count.length; i++)
        {
            while (count[i] > 0)
            {
                array[index++] = i;
                count[i]--;
            }
        }
    }
}
