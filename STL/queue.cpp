#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Create a queue of integers
    queue<int> q;

    // push() - Add elements to the queue
    q.push(10);
    q.push(20);
    q.push(30);
    // Queue now contains: 10, 20, 30

    // front() - Access the front element
    cout << "Front element: " << q.front() << endl; // Output: 10

    // back() - Access the last element
    cout << "Back element: " << q.back() << endl; // Output: 30

    // pop() - Remove the front element
    q.pop();
    // Queue now contains: 20, 30

    // size() - Get the number of elements in the queue
    cout << "Queue size: " << q.size() << endl; // Output: 2

    // empty() - Check if the queue is empty
    if (q.empty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl; // Output: Queue is not empty
    }

    // Display all elements in the queue
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    // Output: 20 30

    return 0;
}