#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    // Unordered sets are containers that store unique elements in no particular order.
    // They are implemented using hash tables.

    // Declaration of an unordered set of integers
    unordered_set<int> uset;

    // Inserting elements into the unordered set
    uset.insert(1);
    uset.insert(2);
    uset.insert(3);
    uset.insert(4);
    uset.insert(5);

    // Elements are not stored in any particular order
    cout << "Elements in the unordered set: ";
    for (const int &elem : uset) {
        cout << elem << " ";
    }
    cout << endl;

    // Checking if an element exists in the unordered set
    if (uset.find(3) != uset.end()) {
        cout << "Element 3 is found in the unordered set." << endl;
    } else {
        cout << "Element 3 is not found in the unordered set." << endl;
    }

    // Erasing an element from the unordered set
    uset.erase(3);
    cout << "Elements in the unordered set after erasing 3: ";
    for (const int &elem : uset) {
        cout << elem << " ";
    }
    cout << endl;

    // Size of the unordered set
    cout << "Size of the unordered set: " << uset.size() << endl;

    // Time Complexity:
    // - Insertion: Average O(1), Worst-case O(n) due to hash collisions
    // - Deletion: Average O(1), Worst-case O(n)
    // - Search: Average O(1), Worst-case O(n)

    // Space Complexity:
    // - The space complexity is O(n) where n is the number of elements in the unordered set.

    return 0;
}