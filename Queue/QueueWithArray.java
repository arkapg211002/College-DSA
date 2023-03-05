/*
 * Queue using Array in java
 */
import java.util.*;
import java.io.*;
import java.lang.*;

public class QueueWithArray {

    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);
        System.out.print("Enter the number of elements in the queue: ");
        int n = console.nextInt();
        Queue queue = new Queue();
        System.out.println("Enter the elements of the queue: ");
        for (int i = 0; i < n; i++)
            queue.enqueue(console.nextInt());
        System.out.println("The queue is: ");
        queue.display();
        System.out.println("The front element of the queue is: " + queue.peek());
        System.out.println("The queue after dequeueing is: ");
        queue.dequeue();
        queue.display();
    }
}

class Queue {

    int[] arr = new int[100];
    int front = -1;
    int rear = -1;

    public void enqueue(int data)
    {
        if (rear == 99)
            System.out.println("Queue Overflow");
        else
        {
            if (front == -1)
                front = 0;
            rear++;
            arr[rear] = data;
        }
    }

    public void dequeue()
    {
        if (front == -1)
            System.out.println("Queue Underflow");
        else
        {
            front++;
            if (front > rear)
            {
                front = -1;
                rear = -1;
            }
        }
    }

    public int peek()
    {
        if (front == -1)
            System.out.println("Queue Underflow");
        else
            return arr[front];
        return -1;
    }

    public void display()
    {
        if (front == -1)
            System.out.println("Queue Underflow");
        else
        {
            for (int i = front; i <= rear; i++)
                System.out.print(arr[i] + " ");
            System.out.println();
        }
    }
}

