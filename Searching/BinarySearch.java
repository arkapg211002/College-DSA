/*
 * This program implements a binary search algorithm.
 */
import java.util.*;
import java.io.*;
import java.lang.*;

public class BinarySearch {
    
    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);
        System.out.print("Enter the number of elements: ");
        int n = console.nextInt();
        int[] array = new int[n];
        System.out.println("Enter the elements in ascending order:");
        for (int i = 0; i < n; i++)
            array[i] = console.nextInt();
        System.out.print("Enter the element to be searched: ");
        int element = console.nextInt();
        int index = binarySearch(array, element);
        if (index == -1)
            System.out.println("The element is not present in the array.");
        else
            System.out.println("The element is present at index " + index);
    }
    
    public static int binarySearch(int[] array, int element) {
        int low = 0;
        int high = array.length - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (array[mid] == element)
                return mid;
            else if (array[mid] < element)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
}
