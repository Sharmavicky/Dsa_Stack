#include <bits/stdc++.h>
using namespace std;

/*
    * @class MinStack
    *
    * @brief Implements a stack that supports retrieving the minimum element
    *        in constant time using an auxiliary value stored with each element.
    *
    * Each stack entry stores a pair:
    *   - first  → actual value pushed
    *   - second → minimum value in the stack at that point
    *
    * Operations:
    *   - push(): Inserts a value and updates the current minimum.
    *   - pop(): Removes the top element.
    *   - top(): Returns the top value of the stack.
    *   - getMin(): Returns the minimum element in O(1) time.
    *
    * Time Complexity:
    *   - push, pop, top, getMin → O(1)
    *
    * Space Complexity:
    *   - O(n), due to storing an extra minimum value with each element.
    *
    * This approach is simple, intuitive, and easy to implement,
    * making it ideal for clarity and interview explanations.
*/

class MinStack {
    public:
    stack<pair<int, int>> stk; // pair<value, current_min>

    MinStack() {} // Constructor

    // Pushes a new value onto the stack and updates the current minimum
    void push(int val) {
        if (stk.empty()) {
            stk.push({val, val});
        } else {
            int currentMin = stk.top().second;
            stk.push({val, min(val, currentMin)});
        }
    }

    // Removes the top element from the stack
    void pop() {
        if (!stk.empty()) stk.pop();
    }

    // Returns the top element of the stack
    int top() {
        if (!stk.empty()) return stk.top().first;
        return -1;
    }

    // Retrieves the minimum element in the stack in O(1) time
    int getMin() {
        if (!stk.empty()) return stk.top().second;
    }
};

/*
    * @class minStack
    *
    * @brief Implements a stack that supports retrieving the minimum element
    *        in constant time using an optimized space technique.
    *
    * Instead of storing pairs, this approach:
    *   - Stores a modified value when a new minimum is pushed.
    *   - Uses mathematical encoding to preserve previous minimum values.
    *
    * Key Idea:
    *   - If a pushed value is smaller than the current minimum,
    *     store (2 * value - currentMin) in the stack.
    *   - This encoded value helps restore the previous minimum during pop().
    *
    * Operations:
    *   - push(): Inserts values with encoding when necessary.
    *   - pop(): Decodes and restores previous minimum if needed.
    *   - top(): Returns the correct top value.
    *   - getMin(): Returns the current minimum in O(1) time.
    *
    * Time Complexity:
    *   - push, pop, top, getMin → O(1)
    *
    * Space Complexity:
    *   - O(n), but more space-efficient than the pair-based approach
    *     since no extra stack or pair storage is used.
    *
    * This method is optimal in terms of space and is commonly used
    * in advanced interview and competitive programming problems.
*/

class minStack {
    public:

    stack<long long int> stk;
    long long int currentMin;

    minStack() {} // Constructor

    void push(int val) {
        if (stk.empty()) {
            stk.push(val);
            currentMin = val;
        } else {
            if (val >= currentMin) {
                stk.push(val);
            } else {
                stk.push((long long)2 * val - currentMin); // Store modified value
                currentMin = val; // Update current minimum
            }
        }
    }

    void pop() {
        if (stk.top() < currentMin) currentMin = 2 * currentMin - stk.top();
        stk.pop();
    }

    int top() {
        if (stk.top() >= currentMin) return stk.top();
        else return currentMin;
    }

    int getMin() {
        return currentMin;
    }
};

// main function
int main() {
    MinStack minStack;

    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    cout << minStack.getMin() << endl; // Returns -3

    minStack.pop();

    cout << minStack.top() << endl;    // Returns 0
    cout << minStack.getMin() << endl; // Returns -2

    return 0;
}