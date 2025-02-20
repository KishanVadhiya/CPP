// gfg url - https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=perfect-sum-problem
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
      int recur(vector<int>& arr,int sum,int i,vector<vector<int>> &dp){
          // if(sum==0) return 1;
          if(i==0){
              return dp[i][sum]=(sum==arr[i])+ (sum==0);
          }
          if(dp[i][sum]!=-1) return dp[i][sum];
          int notPick=recur(arr,sum,i-1,dp);
          int pick=0;
          if(arr[i]<=sum) pick=recur(arr,sum-arr[i],i-1,dp);
          
          return dp[i][sum]=pick+notPick;
      }
      
      int memoization(vector<int>& arr, int target) {
          // code here
          int n=arr.size();
          vector<vector<int>> dp(n,vector<int>(target+1,-1));
          
          return recur(arr,target,n-1,dp);
      }
      
      int tabulation(vector<int>& arr,int target){
          int n=arr.size();
          vector<vector<int>> dp(n,vector<int>(target+1));
          for(int i=0;i<n;i++){
              dp[i][0]=1;
          }
          if(target>=arr[0]) dp[0][arr[0]]++;
          
          for(int i=1;i<n;i++){
              for(int j=0;j<=target;j++){
                  int notPick=dp[i-1][j];
                  int pick=0;
                  if(j>=arr[i]) pick=dp[i-1][j-arr[i]];
                  
                  dp[i][j]=pick+notPick;
              }
          }
          
          return dp[n-1][target];
      }
      
      int memoryOptimization(vector<int>& arr,int target){
          int n=arr.size();
          vector<int> dp(target+1);
          dp[0]=1;
          if(target>=arr[0]) dp[arr[0]]++;
          
          for(int i=1;i<n;i++){
              vector<int> temp(target+1);
              temp[0]=1;
              for(int j=0;j<=target;j++){
                  int notPick=dp[j];
                  int pick=0;
                  if(j>=arr[i]) pick=dp[j-arr[i]];
                  
                  temp[j]=pick+notPick;
              }
              dp=temp;
          }
          return dp[target];
      }
      int perfectSum(vector<int>& arr, int target) {
          // code here
          // return memoization(arr,target);
          // return tabulation(arr,target);
          return memoryOptimization(arr,target);
      }
  };


int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 10;
    cout << "Number of subsets with sum " << target << " is: " << sol.perfectSum(arr, target) << endl;
    return 0;
}