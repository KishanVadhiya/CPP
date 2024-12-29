#include <iostream>
#include <set>

using namespace std;

int main() {
    // Creating a set of integers
    set<int> s;

    // Inserting elements into the set
    s.insert(1); // O(log n)
    s.insert(3); // O(log n)
    s.insert(2); // O(log n)
    s.insert(4); // O(log n)
    s.insert(5); // O(log n)

    // Attempting to insert duplicate elements
    s.insert(2); // No effect, as 2 is already present

    // Displaying elements of the set
    cout << "Elements in the set: ";
    for (int x : s) {
        cout << x << " ";
    }
    cout << endl;

    // Finding an element in the set
    auto it = s.find(2); // O(log n)
    if (it != s.end()) {
        cout << "Element 2 found in the set" << endl;
    } else {
        cout << "Element 2 not found in the set" << endl;
    }

    // Erasing an element from the set
    s.erase(2); // O(log n)
    cout << "Elements in the set after erasing 2: ";
    for (int x : s) {
        cout << x << " ";
    }
    cout << endl;

    // Erasing a range of elements from the set
    auto start = s.find(3);
    auto end = s.find(5);
    if (start != s.end() && end != s.end()) {
        s.erase(start, ++end); // O(k log n), where k is the number of elements being erased
    }
    cout << "Elements in the set after erasing range [3, 5]: ";
    for (int x : s) {
        cout << x << " ";
    }
    cout << endl;

    // Checking the size of the set
    cout << "Size of the set: " << s.size() << endl; // O(1)

    // Clearing the set
    s.clear(); // O(n)
    cout << "Size of the set after clearing: " << s.size() << endl; // O(1)

    return 0;
}