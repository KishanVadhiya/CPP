// leetcode url - https://leetcode.com/problems/triangle/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
    int recur(int i,int j,int n,vector<vector<int>>& arr,vector<vector<int>>& dp){
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==n-1) return dp[i][j]=arr[i][j];
        int down=recur(i+1,j,n,arr,dp);
        int rightDiag=recur(i+1,j+1,n,arr,dp);

        return dp[i][j]=arr[i][j]+min(down,rightDiag);
    }

    int minimumTotalMemoization(vector<vector<int>>& arr){
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return recur(0,0,n,arr,dp);
    }

    int minimumTotalTabulation(vector<vector<int>>& arr){
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        dp[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=dp[i+1][j];
                int rightDiag=dp[i+1][j+1];
                dp[i][j]=arr[i][j]+min(down,rightDiag);
            }
        }

        return dp[0][0];
    }

    int minimumTotalMemoryOptimization1(vector<vector<int>>& arr){
        int n=arr.size();
        vector<int> dp = arr[n-1];

        for(int i=n-2;i>=0;i--){
            vector<int> temp(i+1);
            for(int j=i;j>=0;j--){
                int down=dp[j];
                int rightDiag=dp[j+1];

                temp[j]=arr[i][j]+min(down,rightDiag);
            }
            dp=temp;
        }

        return dp[0];
    }
    int minimumTotalMemoryOptimization2(vector<vector<int>>& triangle) {
        int ans=triangle[0][0];
        int n=triangle.size();
        for(int i=1;i<n;i++){
            ans=INT_MAX;
            for(int j=0;j<i+1;j++){
                int leftDiag=INT_MAX;
                int upper=INT_MAX;

                if(j!=0) leftDiag=triangle[i-1][j-1];
                if(j!=i) upper=triangle[i-1][j];

                triangle[i][j]+=min(leftDiag,upper);
                ans=min(ans,triangle[i][j]);
            }
        }
        return ans;
    }
public:

    int minimumTotal(vector<vector<int>>& triangle) {
        // return minimumTotalMemoization(triangle);
        // return minimumTotalTabulation(triangle);
        // return minimumTotalMemoryOptimization1(triangle);
        return minimumTotalMemoryOptimization2(triangle);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };
    cout << "Minimum path sum: " << sol.minimumTotal(triangle) << endl;
    return 0;
}