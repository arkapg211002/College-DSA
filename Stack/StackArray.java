/*
 * Stack using Array in java
 */
import java.util.*;
import java.io.*;
import java.lang.*;

public class StackArray {
    
    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);
        System.out.print("Enter the size of the stack: ");
        int size = console.nextInt();
        Stack stack = new Stack(size);
        System.out.println("Enter the elements of the stack: ");
        for (int i = 0; i < size; i++)
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
    
    int top;
    int size;
    int[] stack;
    
    public Stack(int size)
    {
        this.size = size;
        stack = new int[size];
        top = -1;
    }
    
    public void push(int data)
    {
        if (top == size - 1)
            System.out.println("Stack Overflow");
        else
        {
            top++;
            stack[top] = data;
        }
    }
    
    public void pop()
    {
        if (top == -1)
            System.out.println("Stack Underflow");
        else
            top--;
    }
    
    public int peek()
    {
        if (top == -1)
        {
            System.out.println("Stack Underflow");
            return -1;
        }
        else
            return stack[top];
    }
    
    public void display()
    {
        if (top == -1)
            System.out.println("Stack Underflow");
        else
        {
            for (int i = top; i >= 0; i--)
                System.out.println(stack[i]);
        }
    }
}

