
#include<iostream>
using namespace std;
class Solution {
    public:
        int minBitFlips(int start, int goal) {
            int differentBits=start^goal;
            int ans=0;
            while(differentBits>0){
                ans++;
                differentBits=differentBits&(differentBits-1);
            }
            return ans;
        }
    };

    int main() {
        Solution sol;
        int start = 10; // Example start number
        int goal = 20;  // Example goal number
        cout << "Minimum bit flips to convert " << start << " to " << goal << " is: " << sol.minBitFlips(start, goal) << endl;
        return 0;
    }