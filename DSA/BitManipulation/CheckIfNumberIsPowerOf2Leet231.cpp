
#include<iostream>
using namespace std;
class Solution {
    public:
        bool isPowerOfTwo(int n) {
            // if(n==0) return false;
            return (n>0 ) && ((n&(n-1))==0);
        }
    };
    int main() {
        Solution solution;
        int num = 13;
        if (solution.isPowerOfTwo(num)) {
            cout << num << " is a power of two." << endl;
        } else {
            cout << num << " is not a power of two." << endl;
        }
        return 0;
    }
