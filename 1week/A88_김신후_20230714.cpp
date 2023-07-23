/*
155. Min Stack
Medium
12.2K
750
Companies
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
*/

#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> elements;     // stack to store elements
    stack<int> minElements;  // stack to store minimum elements

public:
    MinStack() {
        
    }
    
    void push(int val) {
        elements.push(val);  // push the element to the main stack
        
        // check if it's the first element or smaller than the current minimum
        if (minElements.empty() || val <= minElements.top()) {
            minElements.push(val);  // push the element to the min stack
        }
    }
    
    void pop() {
        if (elements.top() == minElements.top()) {
            minElements.pop();  // pop the top element from the min stack if it's the minimum
        }
        
        elements.pop();  // always pop the top element from the main stack
    }
    
    int top() {
        return elements.top();  // return the top element from the main stack
    }
    
    int getMin() {
        return minElements.top();  // return the minimum element from the min stack
    }
};
