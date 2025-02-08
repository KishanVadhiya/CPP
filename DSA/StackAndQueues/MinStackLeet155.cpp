// leetcode url - https://leetcode.com/problems/min-stack/
#include<iostream>
#include<stack>
#include<climits>
using namespace std;
class MinStack {
    stack<int> st;
    stack<int> minSt;
public:
    MinStack() {
        minSt.push(INT_MAX);
    }
    
    void push(int val) {
        st.push(val);
        minSt.push(min(val,minSt.top()));
    }
    
    void pop() {
        minSt.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << "Minimum element: " << obj->getMin() << endl; // Returns -3
    obj->pop();
    cout << "Top element: " << obj->top() << endl; // Returns 0
    cout << "Minimum element: " << obj->getMin() << endl; // Returns -2
    delete obj;
    return 0;
}