//
// Jason Chow - A00942129
//

#pragma once

#include <string>

class MyStack {
public:
    static constexpr int MAX_SIZE = 10;

    MyStack();

    [[nodiscard]] bool full() const;

    [[nodiscard]] bool empty() const;

    bool push(int value);

    void pop();

    [[nodiscard]] int peek() const; // renamed "top" to "peek"

    [[nodiscard]] std::string print() const;

private:
    int arr[MAX_SIZE]{};
    int top;

};