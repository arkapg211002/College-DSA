/*
 * Dequeue using array in java
 */
import java.util.*;
import java.lang.*;
import java.io.*;

public class DequeueWithArray {
    
    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);
        System.out.print("Enter the size of the dequeue: ");
        int size = console.nextInt();
        Dequeue dequeue = new Dequeue(size);
        System.out.println("Enter the elements of the dequeue: ");
        for (int i = 0; i < size; i++)
            dequeue.enqueue(console.nextInt());
        System.out.println("The dequeue is: ");
        dequeue.display();
        System.out.println("The front element of the dequeue is: " + dequeue.peekFront());
        System.out.println("The rear element of the dequeue is: " + dequeue.peekRear());
        System.out.println("The dequeue after dequeueing from front is: ");
        dequeue.dequeueFront();
        dequeue.display();
        System.out.println("The dequeue after dequeueing from rear is: ");
        dequeue.dequeueRear();
        dequeue.display();
    }
}

class Dequeue {
    
    int[] arr;
    int front = -1;
    int rear = -1;
    
    public Dequeue(int size)
    {
        arr = new int[size];
    }
    
    public void enqueue(int data)
    {
        if ((front == 0 && rear == arr.length - 1) || (rear == (front - 1) % (arr.length - 1)))
            System.out.println("Dequeue Overflow");
        else if (front == -1)
        {
            front = 0;
            rear = 0;
            arr[rear] = data;
        }
        else if (rear == arr.length - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }
    
    public void dequeueFront()
    {
        if (front == -1)
            System.out.println("Dequeue Underflow");
        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == arr.length - 1)
            front = 0;
        else
            front++;
    }
    
    public void dequeueRear()
    {
        if (front == -1)
            System.out.println("Dequeue Underflow");
        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
            rear = arr.length - 1;
        else
            rear--;
    }
    
    public int peekFront()
    {
        if (front == -1)
        {
            System.out.println("Dequeue Underflow");
            return -1;
        }
        else
            return arr[front];
    }
    
    public int peekRear()
    {
        if (front == -1)
        {
            System.out.println("Dequeue Underflow");
            return -1;
        }
        else
            return arr[rear];
    }
    
    public void display()
    {
        if (front == -1)
            System.out.println("Dequeue Underflow");
        else
        {
            if (front <= rear)
            {
                for (int i = front; i <= rear; i++)
                    System.out.print(arr[i] + " ");
                System.out.println();
            }
            else
            {
                for (int i = front; i < arr.length; i++)
                    System.out.print(arr[i] + " ");
                for (int i = 0; i <= rear; i++)
                    System.out.print(arr[i] + " ");
                System.out.println();
            }
        }
    }
}

