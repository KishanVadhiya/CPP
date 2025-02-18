// leetcode url - https://leetcode.com/problems/unique-paths-ii/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    int recur(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& arr){
        if(i==0 && j==0) return dp[0][0]=1;
        // if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=0;
        int left=0;
        if(j-1>=0 && arr[i][j-1]==0) left=recur(i,j-1,dp,arr);
        if(i-1>=0 && arr[i-1][j]==0) up=recur(i-1,j,dp,arr);
        return dp[i][j]=up+left;
    }
    int uniquePathsMemo(int m,int n,vector<vector<int>>& arr) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return recur(m-1,n-1,dp,arr);
    }

    int uniquePathsTabulation1(int m,int n,vector<vector<int>>& arr){
        vector<vector<int>> dp(m,vector<int>(n));
        dp[0][0]=1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j+1<n && arr[i][j+1]==0){ // going right side
                    dp[i][j+1]+=dp[i][j];
                }
                if(i+1<m && arr[i+1][j]==0){
                    dp[i+1][j]+=dp[i][j];
                }
            }
        }

        return dp[m-1][n-1];
    }
    int uniquePathsTabulation2(int m,int n,vector<vector<int>>& arr){
        vector<vector<int>> dp(m,vector<int>(n));
        dp[0][0]=1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                int up=0,left=0;
                if(i-1>=0 && arr[i-1][j]==0) up = dp[i-1][j];
                if(j-1>=0 && arr[i][j-1]==0) left=dp[i][j-1];

                dp[i][j]=up+left; 
            }
        }

        return dp[m-1][n-1];
    }


    int uniquePathsMemoryOptimization(int m,int n,vector<vector<int>>& arr){
        vector<int> dp(n);
        for(int i=0;i<m;i++){
            vector<int> temp(n);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    temp[0]=1;
                    continue;
                }
                int up=0,left=0;
                if(i-1>=0 && arr[i-1][j]==0) up = dp[j];
                if(j-1>=0 && arr[i][j-1]==0) left=temp[j-1];

                temp[j]=up+left; 
            }
            dp=temp;
        }

        return dp[n-1];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;

        // return uniquePathsMemo(m,n,obstacleGrid);
        // return uniquePathsTabulation1(m,n,obstacleGrid);
        // return uniquePathsTabulation2(m,n,obstacleGrid);
        return uniquePathsMemoryOptimization(m,n,obstacleGrid);
    }
};


int main() {
    Solution sol;
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    cout << sol.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}