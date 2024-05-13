/* 
 * Stack.cpp
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author: Kyle Wong
 * Date: February 12th, 2024
*/

#include "Stack.h"
#include <cstddef>
#include <iostream>
using namespace std; 


// Default constructor
// Description: Initializes the data members of an object / class
// Postcondition: Stack is empty and its data members set to NULL 
Stack::Stack(){

    this->top = NULL;

}

// Destructor 
// Description: Destroys this object, releasing heap-allocated memory
// Postcondition: All nodes in the linked list are deleted
Stack::~Stack(){

    StackNode * ptrNode = top, *tempNode; // Setting ptrNode to top and creating tempNode pointer

    while (ptrNode != NULL){ // While top of stack is not empty... 

        tempNode = ptrNode; // Setting tempNode to top of stack
        ptrNode = ptrNode->next; // Moving pointer to next element 
        delete tempNode; // Deleting tempNode which stores topmost element 
        tempNode = nullptr; // Setting tempNode back to NULL
    
    }

}

// Push (append) operation 
// Description: Insert new element at the (back) of the linked list / top of the stack
// Postcondition: New inserted element is the new topmost element;
void Stack::push(int data){

    StackNode * tempNode = new StackNode(); // Creating a new node and setting its address as tempNode
    tempNode->data = data; // Set data parameter for tempNode equal to retrieved data parameter from function

    if(this->isEmpty() == true){ // If stack is empty...

        tempNode->next = NULL; // Set next node to NULL
        this->top = tempNode; // Set the top of the stack to tempNode

    }
    else{ // If the stack is not empty...

        StackNode * ptrNode = this->top; // Creating a pointer and assigning the value of top to its address

        while(ptrNode->next != NULL){ // While the next node of top is not empty...

            ptrNode = ptrNode->next; // Traverse until top of stack is reached 

        }

        ptrNode->next = tempNode; // Assign the tempNode and its data to the next node 
        tempNode->next = NULL; // Set the next node of tempNode to NULL

    }

}

// Pop (remove) operation 
// Description: Remove the topmost element of the stack / element at back of the linked list. Returns TRUE if succesful, FALSE otherwise 
// Precondition: Linked list / Stack is not empty 
// Postcondition: Topmost element in the linked list is removed and set to NULL
bool Stack::pop(){

    if(this->isEmpty() != true){ // If the stack is not empty...

        StackNode * currentNode = top; // Creating current node and setting its address to top of stack 
        StackNode * previousNode = NULL; // Creating previous node to keep track of element before current and setting it to NULL

        while(currentNode->next != NULL){ // While the next node is not NULL...

            previousNode = currentNode; // Assign the value of current node to previous node 
            currentNode = currentNode->next; // Traverse to the last node and assign it to current node

        }

        if(previousNode == NULL){ // If previous node remains NULL - the next node of currentNode was NULL - only 1 element in the stack 

            this->top = NULL; // Set the top of the stack to NULL

        }
        else{ // If previous node is no longer NULL - next node of currentNode is not NULL - more than 1 element in the stack 

            previousNode->next = NULL; // Set the next of previous node to NULL, preparing to delete current node 

        }
        delete currentNode; // Delete the topmost element of the original stack (last element in the linked list)
        currentNode = NULL;
        return true;

    }
    else{

        cout << "Stack is empty, cannot pop the top of the stack" << endl;
        return false;

    }

}

// Peek operation 
// Description: Gives access to element at back of linked list / top of the stack and returns that value
// Precondition: Linked list / Stack is not empty 
// Postcondition: Stack must be unchanged 
int Stack::peek(){

    StackNode *currentNode = top; // Create currentNode and set it to top of stack 

    if(this->isEmpty() != true){ // If the top of the stack is not NULL...

        while(currentNode->next != NULL){ // While the next node of currentNode is not NULL...

            currentNode = currentNode->next; // Set currentNode to its next node, traversing until the last element

        }

        return currentNode->data; // Return the data element at the traversed location

    }
    else{ // If the top of the stack is NULL...

        cout << "Top of the stack is NULL, cannot return element" << endl;
        return 0;
        
    }

}

// isEmpty operation 
// Description: Returns TRUE if the stack is empty, FALSE otherwise
// Postcondition: Stack must be unchanged
bool Stack::isEmpty(){

    if(this->top == NULL){

        return true;

    }
    else{

        return false;

    }

}

