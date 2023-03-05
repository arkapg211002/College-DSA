/*
 * Linear Search in java
 */
import java.util.*;
import java.io.*;
import java.lang.*;

public class LinearSearch {
    
    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);
        System.out.print("Enter the number of elements in the array: ");
        int n = console.nextInt();
        int[] array = new int[n];
        System.out.println("Enter the elements of the array: ");
        for (int i = 0; i < n; i++)
            array[i] = console.nextInt();
        System.out.print("Enter the element to be searched: ");
        int element = console.nextInt();
        int index = linearSearch(array, element);
        if (index == -1)
            System.out.println("The element is not present in the array.");
        else
            System.out.println("The element is present at index " + index);
    }
    
    public static int linearSearch(int[] array, int element)
    {
        for (int i = 0; i < array.length; i++)
        {
            if (array[i] == element)
                return i;
        }
        return -1;
    }
}
