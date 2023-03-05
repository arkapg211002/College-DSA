/*
 * Bucket Sort
 */
import java.util.*;
import java.io.*;
import java.lang.*;

public class BucketSort {
    
    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);
        System.out.print("Enter the number of elements in the array: ");
        int n = console.nextInt();
        int[] array = new int[n];
        System.out.println("Enter the elements of the array: ");
        for (int i = 0; i < n; i++)
            array[i] = console.nextInt();
        bucketSort(array);
        System.out.println("The sorted array is: ");
        for (int i = 0; i < n; i++)
            System.out.print(array[i] + " ");
    }
    
    public static void bucketSort(int[] array)
    {
        int max = array[0];
        for (int i = 1; i < array.length; i++)
        {
            if (array[i] > max)
                max = array[i];
        }
        int[] bucket = new int[max + 1];
        for (int i = 0; i < array.length; i++)
        {
            bucket[array[i]]++;
        }
        int j = 0;
        for (int i = 0; i < bucket.length; i++)
        {
            while (bucket[i] > 0)
            {
                array[j++] = i;
                bucket[i]--;
            }
        }
    }
}
