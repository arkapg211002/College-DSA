/*
 * This class implements a circular queue. The queue is implemented as an array
 */

import java.util.*;
import java.io.*;
import java.lang.*;

public class CircularQueue {

    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);
        System.out.print("Enter the size of the queue: ");
        int size = console.nextInt();
        Queue queue = new Queue(size);
        System.out.println("Enter the elements of the queue: ");
        for (int i = 0; i < size; i++)
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

    int[] arr;
    int front = -1;
    int rear = -1;

    public Queue(int size)
    {
        arr = new int[size];
    }

    public void enqueue(int data)
    {
        if ((front == 0 && rear == arr.length - 1) || (rear == (front - 1) % (arr.length - 1)))
            System.out.println("Queue Overflow");
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

    public void dequeue()
    {
        if (front == -1)
            System.out.println("Queue Underflow");
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

    public int peek()
    {
        if (front == -1)
        {
            System.out.println("Queue Underflow");
            return -1;
        }
        else
            return arr[front];
    }

    public void display()
    {
        if (front == -1)
            System.out.println("Queue Underflow");
        else
        {
            int i = front;
            if (front <= rear)
            {
                while (i <= rear)
                    System.out.print(arr[i++] + " ");
            }
            else
            {
                while (i <= arr.length - 1)
                    System.out.print(arr[i++] + " ");
                i = 0;
                while (i <= rear)
                    System.out.print(arr[i++] + " ");
            }
            System.out.println();
        }
    }
}

