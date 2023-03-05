/*
 * Selection Sort
 */
import java.util.*;
import java.io.*;
import java.lang.*;

public class SelectionSort {
    
    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);
        System.out.print("Enter the number of elements in the array: ");
        int n = console.nextInt();
        int[] array = new int[n];
        System.out.println("Enter the elements of the array: ");
        for (int i = 0; i < n; i++)
            array[i] = console.nextInt();
        selectionSort(array);
        System.out.println("The sorted array is: ");
        for (int i = 0; i < n; i++)
            System.out.print(array[i] + " ");
    }
    
    public static void selectionSort(int[] array)
    {
        for (int i = 0; i < array.length - 1; i++)
        {
            int min = i;
            for (int j = i + 1; j < array.length; j++)
            {
                if (array[j] < array[min])
                    min = j;
            }
            int temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
}
