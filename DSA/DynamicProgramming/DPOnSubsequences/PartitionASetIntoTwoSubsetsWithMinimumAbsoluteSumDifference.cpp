// gfg url - https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
class Solution {

    public:
      int minDifference(vector<int>& arr) {
          // Your code goes here
          int target =accumulate(arr.begin(),arr.end(),0);
          int n=arr.size();
          vector<int> dp(target+1,0);
          dp[0]=1;
          if(arr[0]<=target) dp[arr[0]]=1;
          
          for(int i=1;i<n;i++){
              vector<int> temp(target+1,0);
              temp[0]=1;
              for(int j=1;j<=target;j++){
                  bool notTake=dp[j];
                  bool take=false;
                  if(j>=arr[i]) take=dp[j-arr[i]];
                  
                  temp[j]=take||notTake;
              }
              dp=temp;
          }
          int ans=target;
          for(int j=1;j<=target/2;j++){
              if(dp[j]){
                  ans=min(ans,abs(j-(target-j)));
              }
          }
          
          return ans;
      }
  };

int main() {
    Solution sol;
    vector<int> arr = {1, 6, 11, 5};
    cout << "The minimum difference between two subsets is " << sol.minDifference(arr) << endl;
    return 0;
}