// gfg url - https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    bool recur(int idx,int target,int n,vector<int>& arr,vector<vector<int>>& dp){
        if(target==0) return dp[idx][target]=true;
        if(idx==0) return dp[idx][target]=(arr[0]==target);
        if(dp[idx][target]!=-1) return dp[idx][target];
        bool notTake=recur(idx-1,target,n,arr,dp);
        
        bool take=false;
        if(target>=arr[idx]) take=recur(idx-1,target-arr[idx],n,arr,dp);
        
        return dp[idx][target]=(take || notTake);
    }
    
    bool isSubsetSumMemoization(vector<int>& arr,int target){
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        
        return recur(n-1,target,n,arr,dp);
        
    }
    
    bool tabulation(vector<int>& arr,int target){
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        if(arr[0]<=target) dp[0][arr[0]]=1;
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool notTake=dp[i-1][j];
                bool take=false;
                if(j>=arr[i]) take=dp[i-1][j-arr[i]];
                
                dp[i][j]=take || notTake;
            }
        }
        
        return dp[n-1][target];
    }
    
    bool memoryOptimization(vector<int>& arr,int target){
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
        
        return dp[target];
        
    }
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        // return isSubsetSumMemoization(arr,target);
        // return tabulation(arr,target);
        return memoryOptimization(arr,target);
    }
};


    int main() {
        Solution sol;
        vector<int> arr = {3, 34, 4, 12, 5, 2};
        int target = 9;
        if (sol.isSubsetSum(arr, target)) {
            cout << "Found a subset with given target" << endl;
        } else {
            cout << "No subset with given target" << endl;
        }
        return 0;
    }