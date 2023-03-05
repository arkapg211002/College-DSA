/*
 * Tower of Hanoi
 */
import java.util.*;
import java.io.*;
import java.lang.*;

public class TowerOfHanoi {
    
    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);
        System.out.print("Enter the number of disks: ");
        int n = console.nextInt();
        System.out.println("The sequence of moves is:");
        moveDisks(n, 'A', 'B', 'C');
    }
    
    public static void moveDisks(int n, char fromTower, char toTower, char auxTower)
    {
        if (n == 1)
            System.out.println("Move disk " + n + " from " + fromTower + " to " + toTower);
        else
        {
            moveDisks(n - 1, fromTower, auxTower, toTower);
            System.out.println("Move disk " + n + " from " + fromTower + " to " + toTower);
            moveDisks(n - 1, auxTower, toTower, fromTower);
        }
    }
}
