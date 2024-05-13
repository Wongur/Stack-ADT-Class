/* 
 * Stack.h
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author: Kyle Wong
 * Date: February 12th, 2024
 */

class Stack {

    private:
        
        // Description: Nodes for a singly-linked list - Do not modify!
        class StackNode {
            public:
                int data;
                StackNode * next;
        };
        
        // Private data member 
        // Description: Private pointer pointing to the back of linked list / top of stack 
        StackNode * top;

    public:

        // Default constructor
        // Description: Initializes the data members of an object / class
        // Postcondition: Stack is empty and its data members set to NULL
        Stack();

        // Destructor 
        // Description: Destroys this object, releasing heap-allocated memory
        // Postcondition: All nodes in the linked list are deleted 
        ~Stack();

        // Push (append) operation 
        // Description: Insert new element at the (back) of the linked list / top of the stack
        // Postcondition: New inserted element is the new topmost element; 
        void push(int data);

        // Pop (remove) operation 
        // Description: Remove the topmost element of the stack / element at back of the linked list. Returns TRUE if succesful, FALSE otherwise 
        // Precondition: Linked list / Stack is not empty 
        // Postcondition: Topmost element in the linked list is removed and set to NULL 
        bool pop();

        // Peek operation 
        // Description: Gives access to element at back of linked list / top of the stack and returns that value
        // Precondition: Linked list / Stack is not empty 
        // Postcondition: Stack must be unchanged 
        int peek();

        // isEmpty operation 
        // Description: Returns TRUE if the stack is empty, FALSE otherwise
        // Postcondition: Stack must be unchanged 
        bool isEmpty();
  
};

