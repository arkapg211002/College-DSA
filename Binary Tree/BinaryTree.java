/*
 * Binary Tree implementation and its operations in java
 */
import java.util.*;
import java.io.*;
import java.lang.*;

public class BinaryTree {

    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);
        System.out.print("Enter the number of elements in the tree: ");
        int n = console.nextInt();
        BT tree = new BT();
        System.out.println("Enter the elements of the tree: ");
        for (int i = 0; i < n; i++)
            tree.insert(console.nextInt());
        System.out.println("The tree is: ");
        tree.display();
        

    }

}

class Node {

    int data;
    Node left;
    Node right;

    public Node(int data)
    {
        this.data = data;
        left = null;
        right = null;
    }

}

class BT {

    Node root;

    public void insert(int data)
    {
        Node node = new Node(data);
        if (root == null)
            root = node;
        else
        {
            Node n = root;
            while (true)
            {
                if (data < n.data)
                {
                    if (n.left == null)
                    {
                        n.left = node;
                        break;
                    }
                    else
                        n = n.left;
                }
                else
                {
                    if (n.right == null)
                    {
                        n.right = node;
                        break;
                    }
                    else
                        n = n.right;
                }
            }
        }
    }

    public void display()
    {
        display(root);
    }

    public void display(Node node)
    {
        if (node == null)
            return;
        display(node.left);
        System.out.print(node.data + " ");
        display(node.right);
    }

    public int height()
    {
        return height(root);
    }

    public int height(Node node)
    {
        if (node == null)
            return 0;
        else
        {
            int lheight = height(node.left);
            int rheight = height(node.right);
            if (lheight > rheight)
                return lheight + 1;
            else
                return rheight + 1;
        }
    }

    public int countNodes()
    {
        return countNodes(root);
    }

    public int countNodes(Node node)
    {
        if (node == null)
            return 0;
        else
            return countNodes(node.left) + countNodes(node.right) + 1;
    }

    public int countLeafNodes()
    {
        return countLeafNodes(root);
    }

    public int countLeafNodes(Node node)
    {
        if (node == null)
            return 0;
        else if (node.left == null && node.right == null)
            return 1;
        else
            return countLeafNodes(node.left) + countLeafNodes(node.right);
    }

    public int countNonLeafNodes()
    {
        return countNonLeafNodes(root);
    }

    public int countNonLeafNodes(Node node)
    {
        if (node == null)
            return 0;
        else if (node.left == null && node.right == null)
            return 0;
        else
            return countNonLeafNodes(node.left) + countNonLeafNodes(node.right) + 1;
    }

    public int countFullNodes()
    {
        return countFullNodes(root);
    }

    public int countFullNodes(Node node)
    {
        if (node == null)
            return 0;
        else if (node.left == null && node.right == null)
            return 0;
        else if (node.left != null && node.right != null)
            return countFullNodes(node.left) + countFullNodes(node.right) + 1;
        else
            return countFullNodes(node.left) + countFullNodes(node.right);
    }

    public int countHalfNodes()
    {
        return countHalfNodes(root);
    }

    public int countHalfNodes(Node node)
    {
        if (node == null)
            return 0;
        else if (node.left == null && node.right == null)
            return 0;
        else if (node.left != null && node.right != null)
            return countHalfNodes(node.left) + countHalfNodes(node.right);
        else
            return countHalfNodes(node.left) + countHalfNodes(node.right) + 1;
    }

    public int countNodesWithOneChild()
    {
        return countNodesWithOneChild(root);
    }

    public int countNodesWithOneChild(Node node)
    {
        if (node == null)
            return 0;
        else if (node.left == null && node.right == null)
            return 0;
        else if (node.left != null && node.right != null)
            return countNodesWithOneChild(node.left) + countNodesWithOneChild(node.right);
        else
            return countNodesWithOneChild(node.left) + countNodesWithOneChild(node.right) + 1;
    }

    public int countNodesWithTwoChildren()
    {
        return countNodesWithTwoChildren(root);
    }

    public int countNodesWithTwoChildren(Node node)
    {
        if (node == null)
            return 0;
        else if (node.left == null && node.right == null)
            return 0;
        else if (node.left != null && node.right != null)
            return countNodesWithTwoChildren(node.left) + countNodesWithTwoChildren(node.right) + 1;
        else
            return countNodesWithTwoChildren(node.left) + countNodesWithTwoChildren(node.right);
    }

    public int countNodesWithOnlyLeftChild()
    {
        return countNodesWithOnlyLeftChild(root);
    }

    public int countNodesWithOnlyLeftChild(Node node)
    {
        if (node == null)
            return 0;
        else if (node.left == null && node.right == null)
            return 0;
        else if (node.left != null && node.right == null)
            return countNodesWithOnlyLeftChild(node.left) + 1;
        else
            return countNodesWithOnlyLeftChild(node.left) + countNodesWithOnlyLeftChild(node.right);
    }

    public int countNodesWithOnlyRightChild()
    {
        return countNodesWithOnlyRightChild(root);
    }

    public int countNodesWithOnlyRightChild(Node node)
    {
        if (node == null)
            return 0;
        else if (node.left == null && node.right == null)
            return 0;
        else if (node.left == null && node.right != null)
            return countNodesWithOnlyRightChild(node.right) + 1;
        else
            return countNodesWithOnlyRightChild(node.left) + countNodesWithOnlyRightChild(node.right);
    }

    public int countNodesWithNoChildren()
    {
        return countNodesWithNoChildren(root);
    }

    public int countNodesWithNoChildren(Node node)
    {
        if (node == null)
            return 0;
        else if (node.left == null && node.right == null)
            return 1;
        else
            return countNodesWithNoChildren(node.left) + countNodesWithNoChildren(node.right);
    }    

}