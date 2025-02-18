// leetcode url - https://leetcode.com/problems/minimum-path-sum/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
    int recur(int i,int j,vector<vector<int>>& arr,vector<vector<int>>& dp){
        if(i==0 && j==0) return dp[0][0]=arr[0][0];
        int up=INT_MAX;
        int left=INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i-1>=0) up=recur(i-1,j,arr,dp);
        if(j-1>=0) left=recur(i,j-1,arr,dp);


        return dp[i][j]=arr[i][j]+min(up,left);
    }
    int minPathSumMemo(int m,int n,vector<vector<int>>& arr) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return recur(m-1,n-1,arr,dp);
    }

    int minPathTabulation(int m,int n,vector<vector<int>>& arr){
        vector<vector<int>> dp(m,vector<int>(n));
        dp[0][0]=arr[0][0];

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                int up=INT_MAX,left=INT_MAX;
                if(i-1>=0) up=dp[i-1][j];
                if(j-1>=0) left=dp[i][j-1];

                dp[i][j]=arr[i][j]+min(up,left);
            }
        }

        return dp[m-1][n-1];
    }


    int minPathMemoryOptimization(int m,int n,vector<vector<int>>& arr){
        vector<int> dp(n);

        for(int i=0;i<m;i++){
            vector<int> temp(n);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) {
                    temp[j]=arr[0][0];
                    continue;
                }
                int up=INT_MAX,left=INT_MAX;
                if(i-1>=0) up=dp[j];
                if(j-1>=0) left=temp[j-1];

                temp[j]=arr[i][j]+min(up,left);
            }
            dp=temp;
        }

        return dp[n-1];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // return minPathSumMemo(m,n,grid);
        // return minPathTabulation(m,n,grid);
        return minPathMemoryOptimization(m,n,grid);
    }
};


int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << "Minimum Path Sum: " << sol.minPathSum(grid) << endl;
    return 0;
}