import java.util.*;
import java.io.*;
import java.lang.*;

public class AllPermutations
{
    public static void swap(int arr[],int n,int m)
    {
        int temp=arr[n];
        arr[n]=arr[m];
        arr[m]=temp;
    }

    public static void permutations(ArrayList<int[]> res, int arr[], int l, int h)
    {
        if(l==h)
        {
            res.add(Arrays.copyOf(arr,arr.length));
            return;
        }
        for(int i=l;i<arr.length;i++)
        {
            swap(arr,l,i);
            permutations(res,arr,l+1,h);
            swap(arr,l,i);
        }
    }

    public static void main(String args[])
    {
        int arr[]={1,2,3,4};
        ArrayList<int[]> res=new ArrayList<>();
        permutations(res,arr,0,arr.length-1);
        for(int x[]:res)
        {
            for(int a:x)
            {
                System.out.print(a+" ");
            }
            System.out.println();
        }
    }
}
