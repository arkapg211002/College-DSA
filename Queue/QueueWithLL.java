/*
 * This program implements a queue using a linked list.
 */
import java.util.*;
import java.lang.*;
import java.io.*;

public class QueueWithLL {

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

    Node head;
    Node tail;

    public void enqueue(int data)
    {
        Node node = new Node();
        node.data = data;
        node.next = null;
        if (head == null)
            head = node;
        else
            tail.next = node;
        tail = node;
    }

    public void dequeue()
    {
        if (head == null)
            System.out.println("Queue Underflow");
        else
            head = head.next;
    }

    public int peek()
    {
        if (head == null)
        {
            System.out.println("Queue Underflow");
            return -1;
        }
        else
            return head.data;
    }

    public void display()
    {
        Node node = head;
        while (node.next != null)
        {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println(node.data);
    }
}

class Node {

    int data;
    Node next;
}

