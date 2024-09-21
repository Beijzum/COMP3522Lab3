//
// Jason Chow - A00942129
//

#include <sstream>
#include "myStack.hpp"

// MyStack constructor
// POST: Initializes an empty stack with top set to -1.
MyStack::MyStack() : top(-1) {}

// Full function
// POST: Returns true if the stack is full, false otherwise.
bool MyStack::full() const {
    return top == MAX_SIZE - 1;
}

// Empty function
// POST: Returns true if the stack is empty, false otherwise.
bool MyStack::empty() const {
    return top == -1;
}

// Push function
// PRE: value is an integer
// POST: Pushes the value onto the stack.
// RETURN: Returns true if the value is successfully pushed, false otherwise.
bool MyStack::push(int value) {
    if (full()) {
        return false;
    }
    arr[++top] = value;
    return true;
}

// Pop function
// POST: Removes the top element from the stack if it is not empty.
void MyStack::pop() {
    if (!empty()) {
        --top;
    }
}

// Peek function (renamed "top" to "peek")
// POST: Returns the top element of the stack without removing it.
// RETURN: Returns false if stack is empty, otherwise returns the top element.
int MyStack::peek() const {
    if (empty()) {
        return false;
    }
    return arr[top];
}

// Print function
// POST: Returns a string representation of the stack from bottom to top.
// RETURN: Returns a string showing the stack, otherwise returns an empty stack message.
std::string MyStack::print() const {
    if (empty()) {
        return "Stack is empty";
    }

    std::stringstream string;
    string << "Stack from bottom to top (FIFO): [";

    for (int i = 0; i <= top; ++i) {
        string << arr[i];
        if (i != top) {
            string << ", ";
        }
    }
    string << "]";
    return string.str();
}
