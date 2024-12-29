#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    // Create a priority queue (max-heap by default)
    priority_queue<int> pq;

    // Insert elements into the priority queue
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.emplace(5);

    // Display the top element
    cout << "Top element: " << pq.top() << endl;

    // Remove the top element
    pq.pop();

    // Display the top element after pop
    cout << "Top element after pop: " << pq.top() << endl;

    // Check if the priority queue is empty
    if (pq.empty()) {
        cout << "The priority queue is empty." << endl;
    } else {
        cout << "The priority queue is not empty." << endl;
    }

    // Get the size of the priority queue
    cout << "Size of the priority queue: " << pq.size() << endl;

    return 0;
}