#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> s1, s2;

    // Pushing elements into the first stack using push and emplace
    s1.push(10);
    s1.emplace(20);
    s1.push(30);

    // Pushing elements into the second stack using push and emplace
    s2.emplace(40);
    s2.push(50);
    s2.emplace(60);

    // Displaying the top elements before swap
    cout << "Top element of s1 before swap: " << s1.top() << endl;
    cout << "Top element of s2 before swap: " << s2.top() << endl;

    // Swapping the contents of the two stacks
    s1.swap(s2);

    // Displaying the top elements after swap
    cout << "Top element of s1 after swap: " << s1.top() << endl;
    cout << "Top element of s2 after swap: " << s2.top() << endl;

    // Popping elements from the stack
    s1.pop();
    cout << "Top element of s1 after pop: " << s1.top() << endl;

    // Checking if the stack is empty
    if (s1.empty()) {
        cout << "Stack s1 is empty" << endl;
    } else {
        cout << "Stack s1 is not empty" << endl;
    }

    // Getting the size of the stack
    cout << "Size of stack s1: " << s1.size() << endl;

    return 0;
}