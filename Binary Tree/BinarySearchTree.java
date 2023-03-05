/*
 * Binary Search Tree implementation and all its operations
 * 
 * -insert
 * -delete
 * -search
 * -traverse
 * -display
 * -height
 * -size
 * -min
 * -max
 * 
 */
import java.util.*;
import java.io.*;
import java.lang.*;

public class BinarySearchTree {
    
    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);
        System.out.print("Enter the number of elements in the tree: ");
        int n = console.nextInt();
        BST tree = new BST();
        System.out.println("Enter the elements of the tree: ");
        for (int i = 0; i < n; i++)
            tree.insert(console.nextInt());
        System.out.println("The tree is: ");
        tree.display();
        System.out.println("The height of the tree is: " + tree.height());
        System.out.println("The size of the tree is: " + tree.size());
        System.out.println("The minimum element in the tree is: " + tree.min());
        System.out.println("The maximum element in the tree is: " + tree.max());
        System.out.print("Enter the element to be searched: ");
        int search = console.nextInt();
        if (tree.search(search))
            System.out.println(search + " is present in the tree");
        else
            System.out.println(search + " is not present in the tree");
        System.out.print("Enter the element to be deleted: ");
        int delete = console.nextInt();
        tree.delete(delete);
        System.out.println("The tree after deletion is: ");
        tree.display();
        System.out.println("The height of the tree is: " + tree.height());
        System.out.println("The size of the tree is: " + tree.size());
        System.out.println("The minimum element in the tree is: " + tree.min());
        System.out.println("The maximum element in the tree is: " + tree.max());
        System.out.println("The inorder traversal of the tree is: ");
        tree.inorder();
        System.out.println();
        System.out.println("The preorder traversal of the tree is: ");
        tree.preorder();
        System.out.println();
        System.out.println("The postorder traversal of the tree is: ");
        tree.postorder();
        System.out.println();
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

class BST {
    
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
    
    public void display(Node n)
    {
        if (n != null)
        {
            display(n.left);
            System.out.print(n.data + " ");
            display(n.right);
        }
    }
    
    public int height()
    {
        return height(root);
    }
    
    public int height(Node n)
    {
        if (n == null)
            return 0;
        else
        {
            int lheight = height(n.left);
            int rheight = height(n.right);
            if (lheight > rheight)
                return lheight + 1;
            else
                return rheight + 1;
        }
    }
    
    public int size()
    {
        return size(root);
    }
    
    public int size(Node n)
    {
        if (n == null)
            return 0;
        else
            return size(n.left) + size(n.right) + 1;
    }
    
    public int min()
    {
        return min(root);
    }
    
    public int min(Node n)
    {
        if (n.left == null)
            return n.data;
        else
            return min(n.left);
    }
    
    public int max()
    {
        return max(root);
    }
    
    public int max(Node n)
    {
        if (n.right == null)
            return n.data;
        else
            return max(n.right);
    }
    
    public boolean search(int data)
    {
        return search(root, data);
    }
    
    public boolean search(Node n, int data)
    {
        if (n == null)
            return false;
        else if (n.data == data)
            return true;
        else if (data < n.data)
            return search(n.left, data);
        else
            return search(n.right, data);
    }

    public void delete(int data)
    {
        root = delete(root, data);
    }

    public Node delete(Node n, int data)
    {
        if (n == null)
            return null;
        else if (data < n.data)
            n.left = delete(n.left, data);
        else if (data > n.data)
            n.right = delete(n.right, data);
        else
        {
            if (n.left == null && n.right == null)
                return null;
            else if (n.left == null)
                return n.right;
            else if (n.right == null)
                return n.left;
            else
            {
                int min = min(n.right);
                n.data = min;
                n.right = delete(n.right, min);
            }
        }
        return n;
    }

    public void inorder()
    {
        inorder(root);
    }

    public void inorder(Node n)
    {
        if (n != null)
        {
            inorder(n.left);
            System.out.print(n.data + " ");
            inorder(n.right);
        }
    }

    public void preorder()
    {
        preorder(root);
    }

    public void preorder(Node n)
    {
        if (n != null)
        {
            System.out.print(n.data + " ");
            preorder(n.left);
            preorder(n.right);
        }
    }

    public void postorder()
    {
        postorder(root);
    }

    public void postorder(Node n)
    {
        if (n != null)
        {
            postorder(n.left);
            postorder(n.right);
            System.out.print(n.data + " ");
        }
    }

}


