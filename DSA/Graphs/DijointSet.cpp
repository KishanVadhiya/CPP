// gfg url - https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=disjoint-set-union-find

#include <iostream>
using namespace std;

int find(int A[], int X) {
    if (X == A[X]) return A[X];
    return A[X] = find(A, A[X]);
}

void unionSet(int A[], int X, int Z) {
    int UltimateParentX = find(A, X);
    int UltimateParentZ = find(A, Z);
    A[UltimateParentX] = UltimateParentZ;
}

int main() {
    int n = 10; // Example size of the set
    int A[n];
    
    // Initialize the set
    for (int i = 0; i < n; i++) {
        A[i] = i;
    }

    // Perform some union operations
    unionSet(A, 1, 2);
    unionSet(A, 3, 4);
    unionSet(A, 2, 4);

    // Find operations to check the sets
    cout << "Find(1): " << find(A, 1) << endl;
    cout << "Find(2): " << find(A, 2) << endl;
    cout << "Find(3): " << find(A, 3) << endl;
    cout << "Find(4): " << find(A, 4) << endl;
    cout<<endl;
    // Make two sets and find disjoint sets in them
    unionSet(A, 5, 6);
    unionSet(A, 7, 8);

    cout << "Find(5): " << find(A, 5) << endl;
    cout << "Find(6): " << find(A, 6) << endl;
    cout << "Find(7): " << find(A, 7) << endl;
    cout << "Find(8): " << find(A, 8) << endl;
    cout<<endl;

    // Add those two sets together
    unionSet(A, 6, 7);

    // Find operations to check the sets after union
    cout << "Find(5): " << find(A, 5) << endl;
    cout << "Find(6): " << find(A, 6) << endl;
    cout << "Find(7): " << find(A, 7) << endl;
    cout << "Find(8): " << find(A, 8) << endl;

    return 0;
}