/*
 * Merging two sorted linked list in java
 */

import java.util.*;
import java.io.*;
import java.lang.*;

public class Merge {

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
        list3.head = list3.merge(list1.head, list2.head);
        System.out.println("The merged list is: ");
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

    public Node merge(Node head1, Node head2)
    {
        Node p = head1, q = head2;
        Node head = null, tail = null;
        if (p.data < q.data)
        {
            head = tail = p;
            p = p.next;
            tail.next = null;
        }
        else
        {
            head = tail = q;
            q = q.next;
            tail.next = null;
        }
        while (p != null && q != null)
        {
            if (p.data < q.data)
            {
                tail.next = p;
                tail = p;
                p = p.next;
                tail.next = null;
            }
            else
            {
                tail.next = q;
                tail = q;
                q = q.next;
                tail.next = null;
            }
        }
        if (p != null)
            tail.next = p;
        if (q != null)
            tail.next = q;
        return head;
    }
}

class Node {

    int data;
    Node next;
}

