#include <bits/stdc++.h>
#include <List.h>
using namespace std;

/*
    Stack Implementations in C++

    This file demonstrates two approaches to implementing a Stack data structure —
    one using a dynamic array (STL vector) and the other using a custom linked list.

    ✔ Classes:
        1️⃣ vectorStack  → Implements stack using std::vector
            - push(int val): Insert element at top of stack
            - pop(): Remove top element (throws error if empty)
            - top(): Return top element (throws error if empty)
            - isEmpty(): Check if stack is empty

        2️⃣ listStack  → Implements stack using custom linked list (List class)
            - push(int val): Insert element at top of stack
            - pop(): Remove top element (throws error if empty)
            - top(): Return top element (throws error if empty)
            - isEmpty(): Check if stack is empty

    ⚙️ Key Concepts:
        - Demonstrates LIFO (Last-In-First-Out) principle.
        - Highlights difference between array-based and linked list-based implementations.
        - Includes basic error handling for empty stack operations.

    🧠 Learning Goal:
        Understand multiple stack implementation techniques and their trade-offs
        in terms of memory usage and performance.
*/

class vectorStack {
    vector<int> stk;

public:
    int top() {
        if (isEmpty()) throw runtime_error("Stack is empty!!");
        return stk[stk.size()-1];
    }

    void push(int val) {
        stk.push_back(val);
    }

    void pop() {
        if (isEmpty()) throw runtime_error("Stack is empty!!");
        stk.pop_back();
    }

    bool isEmpty() {
        return stk.size() == 0;
    }
};

class listStack {
    List ll;

public:
    int top() {
        if (isEmpty()) throw runtime_error("Stack is empty!!");
        return ll.getHead()->data;
    }

    void push(int val) {
        ll.pushFront(val);
    }

    void pop() {
        if (isEmpty()) throw runtime_error("Stack is empty!!");
        ll.popFront();
    }

    bool isEmpty() {
        return ll.getHead() == NULL;
    }
};

// int main
int main() {
    listStack stk;

    stk.push(10);
    stk.push(20);
    stk.push(30);

    cout << stk.top();
    return 0;
}