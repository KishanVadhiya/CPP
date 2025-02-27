// gfg url - https://www.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1
#include<iostream>
using namespace std;
class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        int totalNumbers=n+1;
        int currentBits=1;
        int ans=0;
        while(n>0){
            currentBits*=2;
            ans+=(totalNumbers/currentBits)*(currentBits/2);
            int remaining=totalNumbers%currentBits - currentBits/2;
            ans+=(max(0,remaining));
            n>>=1;
            // cout<<ans<<endl;
        }
        
        return ans;
    }
};


int main() {
    Solution sol;
    int n = 4;
    cout << "Total set bits from 1 to " << n << " is: " << sol.countSetBits(n) << endl;
    return 0;
}