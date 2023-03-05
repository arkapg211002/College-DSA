/*
 * Binary Insertion Sort
 */
import java.util.*;
import java.io.*;
import java.lang.*;

public class BinaryInsertionSort {
    
    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);
        System.out.print("Enter the number of elements in the array: ");
        int n = console.nextInt();
        int[] array = new int[n];
        System.out.println("Enter the elements of the array: ");
        for (int i = 0; i < n; i++)
            array[i] = console.nextInt();
        binaryInsertionSort(array);
        System.out.println("The sorted array is: ");
        for (int i = 0; i < n; i++)
            System.out.print(array[i] + " ");
    }
    
    public static void binaryInsertionSort(int[] array)
    {
        for (int i = 1; i < array.length; i++)
        {
            int key = array[i];
            int j = binarySearch(array, 0, i - 1, key);
            while (j < i)
            {
                array[j + 1] = array[j];
                j++;
            }
            array[j] = key;
        }
    }
    
    public static int binarySearch(int[] array, int low, int high, int key)
    {
        if (high <= low)
            return (key > array[low]) ? (low + 1) : low;
        int mid = (low + high) / 2;
        if (key == array[mid])
            return mid + 1;
        if (key > array[mid])
            return binarySearch(array, mid + 1, high, key);
        return binarySearch(array, low, mid - 1, key);
    }
}
