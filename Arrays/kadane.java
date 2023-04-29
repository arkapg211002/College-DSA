import java.util.*;
import java.io.*;
import java.lang.*;
public class kadane
{
    public static void main(String args[]) throws IOException
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of elements: ");
        int n=sc.nextInt();
        int a[]=new int[n];
        System.out.println("Enter the elements of the array:");
        for(int i=0;i<n;i++)
        {
            a[i]=sc.nextInt();
        }
        int curmax,globalmax,startindex,endindex,globalstartindex;
        curmax=a[0];
        globalmax=a[0];
        startindex=0;
        endindex=0;
        globalstartindex=0;
        for(int i=1;i<n;i++)
        {
            if(a[i]>a[i]+curmax) 
            {
                startindex=i;
                curmax=a[i];
            }
            else curmax=a[i]+curmax;
            if(curmax>globalmax)
            {
                globalmax=curmax;
                endindex=i;
                globalstartindex=startindex;
            }
        }
        System.out.println("The maximum sum of the subarray is: "+globalmax);
        System.out.println("The subarray is: ");
        for(int i=globalstartindex;i<=endindex;i++)
        {
            System.out.print(a[i]+" ");
        }
        System.out.println();
    }
}
