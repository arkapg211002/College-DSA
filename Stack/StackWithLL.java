/*
 * Stack using Linked List in java
 */
import java.util.*;
import java.io.*;
import java.lang.*;

public class StackWithLL {
    
    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);
        System.out.print("Enter the number of elements in the stack: ");
        int n = console.nextInt();
        Stack stack = new Stack();
        System.out.println("Enter the elements of the stack: ");
        for (int i = 0; i < n; i++)
            stack.push(console.nextInt());
        System.out.println("The stack is: ");
        stack.display();
        System.out.println("The top element of the stack is: " + stack.peek());
        System.out.println("The stack after popping is: ");
        stack.pop();
        stack.display();
    }
}

class Stack {
    
    Node head;
    
    public void push(int data)
    {
        Node node = new Node();
        node.data = data;
        node.next = null;
        if (head == null)
            head = node;
        else
        {
            Node n = head;
            while (n.next != null)
                n = n.next;
            n.next = node;
        }
    }
    
    public void pop()
    {
        if (head == null)
            System.out.println("Stack Underflow");
        else
        {
            Node n = head;
            while (n.next.next != null)
                n = n.next;
            n.next = null;
        }
    }
    
    public int peek()
    {
        if (head == null)
            return -1;
        else
        {
            Node n = head;
            while (n.next != null)
                n = n.next;
            return n.data;
        }
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

