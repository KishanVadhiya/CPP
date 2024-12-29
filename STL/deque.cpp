#include <iostream>
#include <deque>

using namespace std;

int main() {
    // Create a deque of integers
    deque<int> dq;

    // Add elements to the back of the deque
    dq.push_back(1);
    dq.push_back(2);
    dq.emplace_back(3); // emplace_back is similar to push_back but constructs the element in place

    // Add element to the front of the deque
    dq.push_front(0);

    // Print all elements in the deque
    cout << "Deque after push operations: ";
    for (int num : dq) {
        cout << num << " ";
    }
    cout << endl;

    // Remove elements from the back and front of the deque
    dq.pop_back();
    dq.pop_front();

    // Print all elements in the deque after pop operations
    cout << "Deque after pop operations: ";
    for (int num : dq) {
        cout << num << " ";
    }
    cout << endl;

    // Access and print the front and back elements of the deque
    cout << "Front element: " << dq.front() << endl;
    cout << "Back element: " << dq.back() << endl;

    return 0;
}