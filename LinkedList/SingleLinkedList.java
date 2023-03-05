/*
 * Single Linked List in java and its operations
 */

import java.util.*;
import java.io.*;
import java.lang.*;

public class SingleLinkedList {
    
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
    
    public boolean search(int data)
    {
        Node node = head;
        while (node.next != null)
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
            head = node.next;
        else
        {
            while (node.next != null)
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
        node.next = head;
        head = node;
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
        Node n = head;
        while (n.next != null)
            n = n.next;
        n.next = node;
    }

    public void deleteAtStart()
    {
        head = head.next;
    }

    public void deleteAt(int index)
    {
        if (index == 0)
            deleteAtStart();
        else
        {
            Node n = head;
            Node n1 = null;
            for (int i = 0; i < index - 1; i++)
                n = n.next;
            n1 = n.next;
            n.next = n1.next;
            n1 = null;
        }
    }

    public void deleteAtEnd()
    {
        Node n = head;
        Node n1 = null;
        while (n.next != null)
        {
            n1 = n;
            n = n.next;
        }
        n1.next = null;
    }

    public void reverse()
    {
        Node prev = null;
        Node current = head;
        Node next = null;
        while (current != null)
        {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    public void reverseRecursive()
    {
        head = reverseRecursive(head);
    }

    public Node reverseRecursive(Node node)
    {
        if (node == null || node.next == null)
            return node;
        Node rest = reverseRecursive(node.next);
        node.next.next = node;
        node.next = null;
        return rest;
    }

    public void reversePrint()
    {
        reversePrint(head);
    }

    public void reversePrint(Node node)
    {
        if (node == null)
            return;
        reversePrint(node.next);
        System.out.print(node.data + " ");
    }

}

class Node {
    
    int data;
    Node next;
}

