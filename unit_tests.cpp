//
// Jason Chow - A00942129
//

#define CATCH_CONFIG_MAIN

#include "myStack.hpp"
#include "catch.hpp"

TEST_CASE("A new stack is empty", "emptyTest")
{
    MyStack tester;

    REQUIRE(tester.empty() == true);
    REQUIRE(tester.full() == false);
}

TEST_CASE("Push function works", "pushTest") {
    MyStack tester;

    REQUIRE(tester.push(10) == true);
    REQUIRE(tester.empty() == false);
    REQUIRE(tester.push(20) == true);
    REQUIRE(tester.peek() == 20);
}

TEST_CASE("Pop function works", "popTest") {
    MyStack tester;
    tester.push(10);
    tester.push(20);

    tester.pop();
    REQUIRE(tester.peek() == 10);

    tester.pop();
    REQUIRE(tester.empty() == true);
}

TEST_CASE("Pop an empty stack", "popEmptyStackTest") {
    MyStack tester;

    REQUIRE(tester.empty() == true);

    tester.pop();

    REQUIRE(tester.empty() == true);
    REQUIRE(tester.print() == "Stack is empty");
}

TEST_CASE("Pop an empty stack then push", "popEmptyPushStackTest") {
    MyStack tester;

    REQUIRE(tester.empty() == true);

    tester.pop();

    REQUIRE(tester.empty() == true);
    REQUIRE(tester.print() == "Stack is empty");
    REQUIRE(tester.push(1) == true);
    REQUIRE(tester.peek() == 1);
    REQUIRE(tester.print() == "Stack from bottom to top (FIFO): [1]");
}

TEST_CASE("Peek function works", "peekTest") {
    MyStack tester;
    tester.push(10);
    tester.push(20);

    REQUIRE(tester.peek() == 20);
}

TEST_CASE("Check top value on empty stack", "peekEmptyStackTest") {
    MyStack tester;

    REQUIRE(tester.empty() == true);

    REQUIRE(tester.peek() == 0);
}

TEST_CASE("Print function works correctly", "printTest") {
    MyStack tester;
    REQUIRE(tester.print() == "Stack is empty");

    tester.push(10);
    tester.push(20);

    std::string expected_output = "Stack from bottom to top (FIFO): [10, 20]";
    REQUIRE(tester.print() == expected_output);
}

TEST_CASE("Stack is full peek top", "fullStackPeekTest") {
    MyStack tester;

    for (int i = 0; i < MyStack::MAX_SIZE; ++i) {
        REQUIRE(tester.push(i) == true);
    }

    REQUIRE(tester.full() == true);
    REQUIRE(tester.push(100) == false);
    REQUIRE(tester.peek() == 9);
}

TEST_CASE("Push/Pop multiple elements", "pushPopTest") {
    MyStack tester;
    for (int i = 0; i < 5; ++i) {
        tester.push(i);
    }

    std::string expected_output = "Stack from bottom to top (FIFO): [0, 1, 2, 3, 4]";
    REQUIRE(tester.print() == expected_output);

    for (int i = 0; i < 5; ++i) {
        REQUIRE(tester.peek() == 4 - i);
        tester.pop();
    }

    REQUIRE(tester.empty() == true);
    REQUIRE(tester.print() == "Stack is empty");
}

