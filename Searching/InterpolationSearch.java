/*
 * Interpolation Search in java
 */
import java.util.*;
import java.io.*;
import java.lang.*;

public class InterpolationSearch {
    
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
        int index = interpolationSearch(array, element);
        if (index == -1)
            System.out.println("The element is not present in the array.");
        else
            System.out.println("The element is present at index " + index);
    }
    
    public static int interpolationSearch(int[] array, int element)
    {
        int low = 0;
        int high = array.length - 1;
        while (low <= high && element >= array[low] && element <= array[high])
        {
            int pos = low + ((element - array[low]) * (high - low)) / (array[high] - array[low]);
            if (array[pos] == element)
                return pos;
            else if (array[pos] < element)
                low = pos + 1;
            else
                high = pos - 1;
        }
        return -1;
    }
}
