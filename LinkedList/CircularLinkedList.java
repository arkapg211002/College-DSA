/*
 * Circular Linked List in java and its operations
 */
import java.util.*;
import java.io.*;
import java.lang.*;

public class CircularLinkedList {
    
    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);
        System.out.print("Enter the number of elements in the list: ");
        int n = console.nextInt();
        LinkedList list = new LinkedList();
        System.out.println("Enter the elements of the list: ");
        for (int i = 0; i < n; i++)
            list.insert(console.nextInt());
        System.out.println("The list is: ");
        list.display();
        System.out.print("Enter the element to be searched: ");
        int search = console.nextInt();
        if (list.search(search))
            System.out.println(search + " is present in the list.");
        else
            System.out.println(search + " is not present in the list.");
        System.out.print("Enter the element to be deleted: ");
        int delete = console.nextInt();
        list.delete(delete);
        System.out.println("The list after deletion is: ");
        list.display();
    }
}

class LinkedList {
    
    Node head;
    
    public void insert(int data)
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
        node.next = head;
    }
    
    public void display()
    {
        Node node = head;
        while (node.next != head)
        {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println(node.data);
    }
    
    public boolean search(int data)
    {
        Node node = head;
        while (node.next != head)
        {
            if (node.data == data)
                return true;
            node = node.next;
        }
        if (node.data == data)
            return true;
        return false;
    }
    
    public void delete(int data)
    {
        Node node = head;
        if (node.data == data)
        {
            head = node.next;
            node = head;
            while (node.next != head)
                node = node.next;
            node.next = head;
        }
        else
        {
            while (node.next != head)
            {
                if (node.next.data == data)
                {
                    node.next = node.next.next;
                    break;
                }
                node = node.next;
            }
        }
    }

    public void insertAtStart(int data)
    {
        Node node = new Node();
        node.data = data;
        node.next = null;
        if (head == null)
            head = node;
        else
        {
            Node n = head;
            while (n.next != head)
                n = n.next;
            n.next = node;
            node.next = head;
            head = node;
        }
    }

    public void insertAt(int index, int data)
    {
        Node node = new Node();
        node.data = data;
        node.next = null;
        if (index == 0)
            insertAtStart(data);
        else
        {
            Node n = head;
            for (int i = 0; i < index - 1; i++)
                n = n.next;
            node.next = n.next;
            n.next = node;
        }
    }

    public void insertAtEnd(int data)
    {
        Node node = new Node();
        node.data = data;
        node.next = null;
        if (head == null)
            head = node;
        else
        {
            Node n = head;
            while (n.next != head)
                n = n.next;
            n.next = node;
            node.next = head;
        }
    }

    public void deleteAtStart()
    {
        Node node = head;
        head = node.next;
        node = head;
        while (node.next != head)
            node = node.next;
        node.next = head;
    }

    public void deleteAt(int index)
    {
        if (index == 0)
            deleteAtStart();
        else
        {
            Node node = head;
            for (int i = 0; i < index - 1; i++)
                node = node.next;
            node.next = node.next.next;
        }
    }

    public void deleteAtEnd()
    {
        Node node = head;
        while (node.next.next != head)
            node = node.next;
        node.next = head;
    }

    public void reverse()
    {
        Node prev = null;
        Node current = head;
        Node next = null;
        while (current.next != head)
        {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        current.next = prev;
        head = current;
    }

    public void reverseRecursive()
    {
        reverseRecursive(head);
    }

    public void reverseRecursive(Node node)
    {
        if (node.next == head)
        {
            head = node;
            return;
        }
        reverseRecursive(node.next);
        Node q = node.next;
        q.next = node;
        node.next = head;
    }
    
}

class Node {
    
    int data;
    Node next;
}


