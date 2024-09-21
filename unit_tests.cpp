//
// Jason Chow - A00942129
//

#define CATCH_CONFIG_MAIN

#include "myStack.hpp"
#include "catch.hpp"

TEST_CASE("A new stack is empty", "Test")
{
    MyStack tester;

    REQUIRE(tester.empty() == true);
    REQUIRE(tester.full() == false);
}

TEST_CASE("Push function works correctly", "[stack]") {
    MyStack tester;

    REQUIRE(tester.push(10) == true); // Push 10
    REQUIRE(tester.empty() == false); // Stack should not be empty
    REQUIRE(tester.push(20) == true); // Push 20
    REQUIRE(tester.peek() == 20);     // Top element should be 20
}

TEST_CASE("Pop function works correctly", "[stack]") {
    MyStack tester;
    tester.push(10);
    tester.push(20);

    tester.pop(); // Pop top element (20)
    REQUIRE(tester.peek() == 10); // Top element should be 10 now

    tester.pop(); // Pop top element (10)
    REQUIRE(tester.empty() == true); // Stack should be empty now
}

TEST_CASE("Peek function works correctly", "[stack]") {
    MyStack tester;
    tester.push(10);
    tester.push(20);

    REQUIRE(tester.peek() == 20); // Top element should be 20
}

TEST_CASE("Print function works correctly", "[stack]") {
    MyStack tester;
    REQUIRE(tester.print() == "Stack is empty"); // For empty stack

    tester.push(10);
    tester.push(20);

    std::string expected_output = "Stack from bottom to top (FIFO): [10, 20]";
    REQUIRE(tester.print() == expected_output); // For stack with elements 10, 20
}

TEST_CASE("Stack becomes full and push fails", "[stack]") {
    MyStack tester;

    for (int i = 0; i < MyStack::MAX_SIZE; ++i) {
        REQUIRE(tester.push(i) == true);
    }

    REQUIRE(tester.full() == true);
    REQUIRE(tester.push(100) == false);
}

TEST_CASE("Push/Pop multiple elements", "[stack]") {
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
