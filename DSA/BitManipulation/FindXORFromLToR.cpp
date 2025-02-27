// gfg url - https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-xor-of-numbers-from-l-to-r
#include<iostream>
using namespace std;
class Solution {
    public:
      int findXOR(int l, int r) {
          // complete the function here
          l--;
          if(l%4==0) l=l;
          else if(l%4==1) l=1;
          else if(l%4==2) l=l+1;
          else l=0;
          
          if(r%4==0) r=r;
          else if(r%4==1) r=1;
          else if(r%4==2) r=r+1;
          else r=0;
          
          return l^r;
      }
  };
  

int main() {
    Solution sol;
    int l = 3, r = 9;
    cout << "XOR from " << l << " to " << r << " is: " << sol.findXOR(l, r) << endl;
    return 0;
}