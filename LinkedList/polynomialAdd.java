/*
 * polynomial addition with linked list in java
 */

import java.util.*;
import java.io.*;
import java.lang.*;

public class polynomialAdd {

    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);
        System.out.print("Enter the number of elements in the first list: ");
        int n = console.nextInt();
        LinkedList list1 = new LinkedList();
        System.out.println("Enter the elements of the first list: ");
        for (int i = 0; i < n; i++)
            list1.insert(console.nextInt());
        System.out.print("Enter the number of elements in the second list: ");
        int m = console.nextInt();
        LinkedList list2 = new LinkedList();
        System.out.println("Enter the elements of the second list: ");
        for (int i = 0; i < m; i++)
            list2.insert(console.nextInt());
        LinkedList list3 = new LinkedList();
        list3.head = list3.add(list1.head, list2.head);
        System.out.println("The added list is: ");
        list3.display();
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

    public Node add(Node head1, Node head2)
    {
        Node node1 = head1;
        Node node2 = head2;
        Node node3 = null;
        while (node1 != null && node2 != null)
        {
            if (node1.data < node2.data)
            {
                node3 = insert(node3, node1.data);
                node1 = node1.next;
            }
            else if (node1.data > node2.data)
            {
                node3 = insert(node3, node2.data);
                node2 = node2.next;
            }
            else
            {
                node3 = insert(node3, node1.data);
                node1 = node1.next;
                node2 = node2.next;
            }
        }
        while (node1 != null)
        {
            node3 = insert(node3, node1.data);
            node1 = node1.next;
        }
        while (node2 != null)
        {
            node3 = insert(node3, node2.data);
            node2 = node2.next;
        }
        return node3;
    }

    public Node insert(Node head, int data)
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
        return head;
    }
}

class Node {

    int data;
    Node next;
}

