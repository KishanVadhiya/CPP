// leetcode url - https://leetcode.com/problems/minimum-falling-path-sum/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
    int recur(int i,int j,int n,vector<vector<int>>& arr,vector<vector<int>>& dp){
        if(i<0 || i>=n || j<0 || j>=n) return INT_MAX;
        if(i==0) return dp[i][j]=arr[i][j];
        if(dp[i][j]!=-101) return dp[i][j];
        int left=recur(i-1,j-1,n,arr,dp);
        int up=recur(i-1,j,n,arr,dp);
        int right=recur(i-1,j+1,n,arr,dp);

        return dp[i][j]=arr[i][j]+min(left,min(up,right));
    }
    int minFallingPathSumMemoization(vector<vector<int>>& matrix){
        int ans=INT_MAX;
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-101));
        for(int i=0;i<n;i++){
            ans=min(ans,recur(n-1,i,n,matrix,dp));
        }
        return ans;
    }

    int minFallingPathSumTabulation(vector<vector<int>>& arr){
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n));
        dp[0]=arr[0];

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int up=dp[i-1][j];
                int left=(j-1>=0)?dp[i-1][j-1]:INT_MAX;
                int right=(j+1<n)?dp[i-1][j+1]:INT_MAX;

                dp[i][j]=arr[i][j]+min(up,min(left,right));
            }
        }
        
        int ans=INT_MAX;
        for(auto it:dp[n-1]){
            ans=min(it,ans);
        }
        return ans;
    }

    int minFallingPathSumMemoryOptimization(vector<vector<int>>& arr){
        int n=arr.size();
        vector<int> dp=arr[0];

        for(int i=1;i<n;i++){
            vector<int> temp(n);
            for(int j=0;j<n;j++){
                int up=dp[j];
                int left=(j-1>=0)?dp[j-1]:INT_MAX;
                int right=(j+1<n)?dp[j+1]:INT_MAX;

                temp[j]=arr[i][j]+min(up,min(left,right)); 
            }
            dp=temp;
        }

        int ans=INT_MAX;
        for(auto it:dp){
            ans=min(ans,it);
        }
        return ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // return minFallingPathSumMemoization(matrix);
        // return minFallingPathSumTabulation(matrix);
        return minFallingPathSumMemoryOptimization(matrix);
    }
};


int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };
    cout << "Minimum Falling Path Sum: " << sol.minFallingPathSum(matrix) << endl;
    return 0;
}