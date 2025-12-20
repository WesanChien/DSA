#include <iostream>
#include <stack>

using namespace std;

class MinStack1{
private :
    stack<int> stack1;
    stack<int> minValStack;
public:
    MinStack() {
    }
    
    void push(int val) {
        stack1.push(val);
        val = min(val, minValStack.empty() ? val : minValStack.top());
        minValStack.push(val);
    }
    
    void pop() {
        stack1.pop();
        minValStack.pop();
    }
    
    int top() {
        return stack1.top();
    }
    
    int getMin() {
        return minValStack.top();
    }
};

int main(){
    MinStack minStack;
    minStack.push(1);
    minStack.push(2);
    minStack.push(0);
    minStack.getMin(); // return 0
    minStack.pop();
    minStack.top();    // return 2
    minStack.getMin(); // return 1
    return 0;
}