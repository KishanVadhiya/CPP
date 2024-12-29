#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// The sort function in C++ STL is used to sort elements in a range.
// It can be used in several ways:

// 1. Sorting an array in ascending order
void sortArrayAscending() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr + n);
    cout << "Array sorted in ascending order: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 2. Sorting an array in descending order
void sortArrayDescending() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr + n, greater<int>());
    cout << "Array sorted in descending order: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 3. Sorting a vector in ascending order
void sortVectorAscending() {
    vector<int> vec = {5, 2, 9, 1, 5, 6};
    sort(vec.begin(), vec.end());
    cout << "Vector sorted in ascending order: ";
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

// 4. Sorting a vector in descending order
void sortVectorDescending() {
    vector<int> vec = {5, 2, 9, 1, 5, 6};
    sort(vec.begin(), vec.end(), greater<int>());
    cout << "Vector sorted in descending order: ";
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

// __builtin_popcount: Counts the number of set bits in an unsigned int
void countSetBits() {
    unsigned int x = 29; // binary: 11101
    int count = __builtin_popcount(x);
    cout << "Number of set bits in " << x << " is " << count << endl;
}

// __builtin_popcountll: Counts the number of set bits in an unsigned long long
void countSetBitsLL() {
    unsigned long long x = 29; // binary: 11101
    int count = __builtin_popcountll(x);
    cout << "Number of set bits in " << x << " is " << count << endl;
}

// next_permutation example with loop
void nextPermutationExample() {
    vector<int> vec = {1, 2, 3};
    cout << "All permutations: " << endl;
    do {
        for (int i = 0; i < vec.size(); ++i) {
            cout << vec[i] << " ";
        }
        cout << endl;
    } while (next_permutation(vec.begin(), vec.end()));
}

int main() {
    sortArrayAscending();
    sortArrayDescending();
    sortVectorAscending();
    sortVectorDescending();
    countSetBits();
    countSetBitsLL();
    nextPermutationExample();
    return 0;
}