// gfg url - https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=matrix-chain-multiplication
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
    int recur(int i,int j,vector<int>& arr,vector<vector<int>>& dp){
        if(i==j) return dp[i][j]=0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k=i;k<j;k++){
            int operations=(arr[i-1]*arr[k]*arr[j]) + recur(i,k,arr,dp) + recur(k+1,j,arr,dp);
            mini=min(mini,operations);
        }
        
        return dp[i][j]=mini;
    }
    
    int memoization(vector<int>& arr){
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return recur(1,n-1,arr,dp);
    }
    
    int tabulation(vector<int>& arr){
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n));
        
        for(int i=n-1;i>0;i--){
            for(int j=i+1;j<n;j++){
                // if(i==j) continue;
                int mini=INT_MAX;
                for(int k=i;k<j;k++){
                    int operations=(arr[i-1]*arr[k]*arr[j]) + dp[i][k]+dp[k+1][j];
                    mini=min(mini,operations);
                }
                
                dp[i][j]=mini;
            }
        }
        
        return dp[1][n-1];
    }
    
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        // return memoization(arr);
        return tabulation(arr);
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 3};
    Solution sol;
    cout << "Minimum number of multiplications is " << sol.matrixMultiplication(arr) << endl;
    return 0;
}