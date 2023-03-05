/*
 * This program uses recursion to evaluate a polynomial
 * using Horner's rule.
 */
 
 import java.util.*;
 import java.io.*;
 import java.lang.*;

 public class HornersRecursion
 {
     public static void main(String[] args)
     {
         Scanner console = new Scanner(System.in);
         System.out.print("Enter the degree of the polynomial: ");
         int degree = console.nextInt();
         int[] coefficients = new int[degree + 1];
         for (int i = 0; i <= degree; i++)
         {
             System.out.print("Enter the coefficient of x^" + i + ": ");
             coefficients[i] = console.nextInt();
         }
         System.out.print("Enter the value of x: ");
         int x = console.nextInt();
         int result = horner(coefficients, degree, x);
         System.out.println("The value of the polynomial is " + result);
     }
     
     public static int horner(int[] coefficients, int degree, int x)
     {
         if (degree == 0)
             return coefficients[0];
         else
             return coefficients[degree] + x * horner(coefficients, degree - 1, x);
     }
 }