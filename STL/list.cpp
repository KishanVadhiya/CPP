#include <iostream>
#include <list>  // Include the list header for std::list
using namespace std;

void printList(const list<int>& lst) {
    cout << "List elements: ";
    for (auto i : lst) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    // Create an empty list of integers
    list<int> myList;

    // Add elements to the back of the list
    myList.emplace_back(5);  // Emplace generates the value directly in place
    myList.push_back(10);    // Push copies the value to the back

    // Add elements to the front of the list
    myList.push_front(3);    // Push copies the value to the front
    int x = 1;
    myList.emplace_front(x); // Emplace generates the value directly in place

    // Modify the first element of the list
    x = 2;
    *(myList.begin()) = 0;   // Change the first element to 0

    // Print the list elements
    printList(myList);

    // Print the value of x
    cout << "Value of x: " << x << endl;

    // Remove elements from the list
    myList.pop_front();      // Remove the first element
    myList.pop_back();       // Remove the last element

    // Print the list elements after removal
    printList(myList);

    // Insert elements at a specific position
    auto it = myList.begin();
    advance(it, 1);          // Move iterator to the second position
    myList.insert(it, 7);    // Insert 7 at the second position

    // Print the list elements after insertion
    printList(myList);

    // Erase elements at a specific position
    it = myList.begin();
    advance(it, 1);          // Move iterator to the second position
    myList.erase(it);        // Erase the element at the second position

    // Print the list elements after erasure
    printList(myList);

    // Clear the entire list
    myList.clear();

    // Check if the list is empty
    if (myList.empty()) {
        cout << "The list is now empty." << endl;
    }

    return 0;
}