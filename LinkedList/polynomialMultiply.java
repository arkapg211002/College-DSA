/*
 * This program multiplies two polynomials represented as linked lists.
 */

import java.util.*;
import java.io.*;
import java.lang.*;

public class polynomialMultiply {

    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);
        System.out.print("Enter the number of elements in the first polynomial: ");
        int n = console.nextInt();
        LinkedList list1 = new LinkedList();
        System.out.println("Enter the elements of the first polynomial: ");
        for (int i = 0; i < n; i++)
            list1.insert(console.nextInt());
        System.out.print("Enter the number of elements in the second polynomial: ");
        int m = console.nextInt();
        LinkedList list2 = new LinkedList();
        System.out.println("Enter the elements of the second polynomial: ");
        for (int i = 0; i < m; i++)
            list2.insert(console.nextInt());
        LinkedList list3 = new LinkedList();
        list3.head = list3.multiply(list1.head, list2.head);
        System.out.println("The product of the two polynomials is: ");
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

    public Node multiply(Node head1, Node head2)
    {
        Node node1 = head1;
        Node node2 = head2;
        Node head3 = null;
        while (node1 != null)
        {
            while (node2 != null)
            {
                int data = node1.data * node2.data;
                if (head3 == null)
                {
                    head3 = new Node();
                    head3.data = data;
                    head3.next = null;
                }
                else
                {
                    Node node3 = head3;
                    while (node3.next != null)
                        node3 = node3.next;
                    node3.next = new Node();
                    node3.next.data = data;
                    node3.next.next = null;
                }
                node2 = node2.next;
            }
            node1 = node1.next;
            node2 = head2;
        }
        return head3;
    }
}

class Node {

    int data;
    Node next;
}

