/*
 * Recursive Binary Search
 */
import java.util.*;
import java.io.*;
import java.lang.*;

public class BinarySearchrecursive {
    
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
        int index = binarySearch(array, element, 0, n - 1);
        if (index == -1)
            System.out.println("The element is not present in the array.");
        else
            System.out.println("The element is present at index " + index);
    }
    
    public static int binarySearch(int[] array, int element, int low, int high)
    {
        if (low > high)
            return -1;
        int mid = (low + high) / 2;
        if (array[mid] == element)
            return mid;
        else if (array[mid] < element)
            return binarySearch(array, element, mid + 1, high);
        else
            return binarySearch(array, element, low, mid - 1);
    }
}
