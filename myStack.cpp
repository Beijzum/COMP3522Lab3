//
// Jason Chow - A00942129
//

#include <sstream>
#include "myStack.hpp"

MyStack::MyStack() : top(-1) {}

bool MyStack::full() const {
    return top == MAX_SIZE - 1;
}

bool MyStack::empty() const {
    return top == -1;
}

bool MyStack::push(int value) {
    if (full()) {
        return false;
    }
    arr[++top] = value;
    return true;
}

void MyStack::pop() {
    if (!empty()) {
        --top;
    }
}

int MyStack::peek() const { // renamed "top" to "peek"
    if (empty()) {
        return false;
    }
    return arr[top];
}

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
