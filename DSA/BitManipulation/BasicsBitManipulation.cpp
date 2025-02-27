
#include<iostream>
using namespace std;
class Solution {
    public:
      void bitManipulation(int num, int i) {
          // your code here
          int bitVal=1<<(i-1);
          //check if ith bit is set or not , set ith bit , reset the ith bit
          cout<<((num&bitVal)!=0)<<" "<<(num|bitVal)<<" "<<(num&(~bitVal));
      }
  };

int main() {
    Solution sol;
    int num = 70, i = 3;
    sol.bitManipulation(num, i);
    return 0;
}
