// gfg url - https://www.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1
#include<iostream>
#include<cmath>
using namespace std;
class Solution {
    public:
      int sumOfDivisors(int n) {
          // Write Your Code here
          if(n==0) return 0;
          int ans=0;
          int i=1;
          for(;i*i<n;i++){
              if(n%i==0){
                  ans+=i+n/i;
              }
          }
          if(i*i==n) ans+=i;
          return ans+sumOfDivisors(n-1);
      }
  };


int main() {
    Solution sol;
    int n = 4;
    cout << "Sum of all divisors from 1 to " << n << " is: " << sol.sumOfDivisors(n) << endl;
    return 0;
}
