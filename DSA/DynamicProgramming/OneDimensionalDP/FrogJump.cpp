// gfg url - https://www.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
      int minCost(vector<int>& height) {
          // Code here
          int n=height.size();
          if(n==1) return 0;
          int a=0;
          int b=abs(height[1]-height[0]);
          
          for(int i=2;i<n;i++){
              int cost=min(abs(height[i]-height[i-1])+b,abs(height[i]-height[i-2])+a);
              
              a=b;
              b=cost;
          }
          
          
          
          return b;
          
          
      }

  };



int main() {
    Solution sol;
    vector<int> height = {10, 30, 40, 20};
    cout << "Minimum cost: " << sol.minCost(height) << endl;
    return 0;
}