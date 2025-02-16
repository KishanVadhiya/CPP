// gfg url - https://www.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
    public:
      int minimizeCost(int k, vector<int>& arr) {
          // Code here
          int n=arr.size();
          vector<int> dp(n,-1);
          dp[0]=0;
          
          for(int i=1;i<n;i++){
              int minn=INT_MAX;
              for(int j=i-1;j>=0 && j>=i-k;j--){
                  minn=min(minn,abs(arr[i]-arr[j])+dp[j]);
                  dp[i]=minn;
              }
          }
          
          return dp[n-1];
      }
  };

int main() {
    Solution sol;
    int k = 2;
    vector<int> arr = {10, 30, 40, 50, 20};
    cout << "The minimal cost is: " << sol.minimizeCost(k, arr) << endl;
    return 0;
}