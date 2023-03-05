/*
 * Double Linked List in java and its operations
 */
import java.util.*;
import java.io.*;
import java.lang.*;

public class DoubleLinkedList {
    
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
        node.prev = null;
        if (head == null)
            head = node;
        else
        {
            Node n = head;
            while (n.next != null)
                n = n.next;
            n.next = node;
            node.prev = n;
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
        while (node.next != null)
        {
            if (node.data == data)
            {
                if (node.prev == null)
                {
                    head = node.next;
                    node.next.prev = null;
                }
                else
                {
                    node.prev.next = node.next;
                    node.next.prev = node.prev;
                }
                return;
            }
            node = node.next;
        }
        if (node.data == data)
        {
            if (node.prev == null)
            {
                head = node.next;
                node.next.prev = null;
            }
            else
            {
                node.prev.next = node.next;
                node.next.prev = node.prev;
            }
        }
    }

    public void reverse()
    {
        Node node = head;
        while (node.next != null)
            node = node.next;
        while (node.prev != null)
        {
            System.out.print(node.data + " ");
            node = node.prev;
        }
        System.out.println(node.data);
    }

    public void reverseDisplay()
    {
        Node node = head;
        while (node.next != null)
            node = node.next;
        while (node.prev != null)
        {
            System.out.print(node.data + " ");
            node = node.prev;
        }
        System.out.println(node.data);
    }

}

class Node {
    
    int data;
    Node next;
    Node prev;
}


