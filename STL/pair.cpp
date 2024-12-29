#include <iostream>
using namespace std;

int main() {
    // Creating a pair of integers
    pair<int, int> p;
    p.first = 25;  // Assigning value to the first element of the pair
    p.second = 2;  // Assigning value to the second element of the pair

    // Output the second element of the pair
    cout << p.second << endl;

    // Creating a nested pair
    pair<int, pair<int, int>> x = make_pair(1, make_pair(5, 6));

    // Output the second element of the nested pair
    cout << x.second.second << endl;

    return 0;
}