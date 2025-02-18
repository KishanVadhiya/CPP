// leetcode url - https://leetcode.com/problems/unique-paths/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    int recur(int i,int j,vector<vector<int>>& dp){
        if(i==0 && j==0) return dp[0][0]=1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=recur(i,j-1,dp);
        int left=recur(i-1,j,dp);
        return dp[i][j]=up+left;
    }
    int uniquePathsMemo(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return recur(m-1,n-1,dp);
    }

    int uniquePathsTabulation1(int m,int n){
        vector<vector<int>> dp(m,vector<int>(n));
        dp[0][0]=1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j+1<n){ // going right side
                    dp[i][j+1]+=dp[i][j];
                }
                if(i+1<m){
                    dp[i+1][j]+=dp[i][j];
                }
            }
        }

        return dp[m-1][n-1];
    }
    int uniquePathsTabulation2(int m,int n){
        vector<vector<int>> dp(m,vector<int>(n));
        dp[0][0]=1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                int up=0,left=0;
                if(i-1>=0) up = dp[i-1][j];
                if(j-1>=0) left=dp[i][j-1];

                dp[i][j]=up+left; 
            }
        }

        return dp[m-1][n-1];
    }


    int uniquePathsMemoryOptimization(int m,int n){
        vector<int> dp(n);
        for(int i=0;i<m;i++){
            vector<int> temp(n);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    temp[0]=1;
                    continue;
                }
                int up=0,left=0;
                if(i-1>=0) up = dp[j];
                if(j-1>=0) left=temp[j-1];

                temp[j]=up+left; 
            }
            dp=temp;
        }

        return dp[n-1];
    }
public:
    int uniquePaths(int m, int n) {
        
        // return uniquePathsMemo(m,n);
        // return uniquePathsTabulation1(m,n);
        // return uniquePathsTabulation2(m,n);
        return uniquePathsMemoryOptimization(m,n);
    }
};


int main() {
    Solution sol;
    int m = 3, n = 7;
    cout << "Number of unique paths for a " << m << "x" << n << " grid: " << sol.uniquePaths(m, n) << endl;
    return 0;
}