/*
 * Radix Sort
 */
import java.util.*;
import java.io.*;
import java.lang.*;

public class RadixSort {
    
    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);
        System.out.print("Enter the number of elements in the array: ");
        int n = console.nextInt();
        int[] array = new int[n];
        System.out.println("Enter the elements of the array: ");
        for (int i = 0; i < n; i++)
            array[i] = console.nextInt();
        radixSort(array);
        System.out.println("The sorted array is: ");
        for (int i = 0; i < n; i++)
            System.out.print(array[i] + " ");
    }
    
    public static void radixSort(int[] array)
    {
        int max = getMax(array);
        for (int exp = 1; max / exp > 0; exp *= 10)
            countSort(array, exp);
    }
    
    public static void countSort(int[] array, int exp)
    {
        int[] output = new int[array.length];
        int[] count = new int[10];
        for (int i = 0; i < array.length; i++)
            count[(array[i] / exp) % 10]++;
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];
        for (int i = array.length - 1; i >= 0; i--)
        {
            output[count[(array[i] / exp) % 10] - 1] = array[i];
            count[(array[i] / exp) % 10]--;
        }
        for (int i = 0; i < array.length; i++)
            array[i] = output[i];
    }
    
    public static int getMax(int[] array)
    {
        int max = array[0];
        for (int i = 1; i < array.length; i++)
            if (array[i] > max)
                max = array[i];
        return max;
    }
}
