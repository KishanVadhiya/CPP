#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Creating vectors
    vector<int> x; // Empty vector
    vector<int> x2(5); // Vector of size 5 with default values (0)
    vector<int> x3(5, -1); // Vector of size 5 with all values initialized to -1

    // Adding elements to vector x
    x.push_back(2);
    x.push_back(3);
    x.emplace_back(0); // emplace_back is similar to push_back but more efficient
    x.emplace_back(-1);
    x.push_back(5);

    // Resizing vector x to size 10, new elements initialized to 5
    x.resize(10, 5);

    // Printing elements of vector x
    for (int i = 0; i < x.size(); i++) {
        cout << x[i] << " ";
    }
    cout << endl << x.capacity() << endl << endl; // Printing capacity of vector x

    // Using iterators with vector a
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);

    // Iterator to the beginning of vector a
    vector<int>::iterator it = a.begin();
    cout << *it << endl;
    cout << *(it + 1) << endl;
    cout << *(it + 2) << endl;
    cout << *(it + 3) << endl;
    cout << *(it + 4) << endl;
    cout << endl;

    // Iterator to the end of vector a
    vector<int>::iterator itend = a.end();
    cout << *(itend - 1) << endl << endl;

    // Iterating through vector a using iterator
    for (vector<int>::iterator i = a.begin(); i != a.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    // Erasing elements from vector a
    a.erase(a.begin() + 1); // Erase second element
    for (auto i : a) {
        cout << i << " ";
    }
    cout << endl;

    a.erase(a.begin(), a.begin() + 2); // Erase first two elements
    for (auto i = a.begin(); i != a.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    // Inserting elements into vector a
    vector<int> cpy(2, 50); // Vector of size 2 with all values initialized to 50
    cpy.insert(cpy.begin(), -10); // Insert -10 at the beginning of cpy
    a.insert(a.begin(), cpy.begin(), cpy.end()); // Insert elements of cpy at the beginning of a

    // Removing the last element of vector a
    a.pop_back();

    // Printing elements of vector a
    for (auto i = a.begin(); i != a.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;

    // Clearing all elements of vector a
    a.clear();
    cout << a.empty(); // Check if vector a is empty

    return 0;
}
