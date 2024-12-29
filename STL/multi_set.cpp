#include <iostream>
#include <set>

using namespace std;

int main() {
    // Multiset is an associative container that contains a sorted set of duplicate objects of type Key.
    // It is usually implemented using a balanced binary search tree.

    multiset<int> ms;

    // Insert elements
    ms.insert(5);
    ms.insert(10); // O(log n)
    ms.insert(20); // O(log n)
    ms.insert(10); // O(log n)
    ms.insert(30); // O(log n)
    ms.insert(20); // O(log n)
    ms.insert(40); // O(log n)
    ms.insert(30); // O(log n)
    ms.insert(50); // O(log n)
    ms.insert(10); // O(log n)

    // Display elements
    cout << "Multiset elements: ";
    for (int x : ms) {
        cout << x << " ";
    }
    cout << endl;

    // Count occurrences of an element
    cout << "Count of 10: " << ms.count(10) << endl; // O(log n)
    cout << "Count of 20: " << ms.count(20) << endl; // O(log n)

    // Find an element
    auto it = ms.find(20); // O(log n)
    if (it != ms.end()) {
        cout << "Element 20 found" << endl;
    } else {
        cout << "Element 20 not found" << endl;
    }

    // Erase an element
    ms.erase(10); // O(log n)
    cout << "Multiset elements after erasing 10: ";
    for (int x : ms) {
        cout << x << " ";
    }
    cout << endl;

    // Erase all elements with a specific value
    ms.erase(ms.find(20), ms.upper_bound(20)); // O(log n)
    cout << "Multiset elements after erasing all 20s: ";
    for (int x : ms) {
        cout << x << " ";
    }
    cout << endl;

    // Lower bound
    auto lb = ms.lower_bound(15); // O(log n)
    if (lb != ms.end()) {
        cout << "Lower bound of 15: " << *lb << endl;
    } else {
        cout << "Lower bound of 15 not found" << endl;
    }

    // Upper bound
    auto ub = ms.upper_bound(15); // O(log n)
    if (ub != ms.end()) {
        cout << "Upper bound of 15: " << *ub << endl;
    } else {
        cout << "Upper bound of 15 not found" << endl;
    }

    // Equal range
    auto range = ms.equal_range(10); // O(log n)
    cout << "Equal range of 10: ";
    for (auto it = range.first; it != range.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}