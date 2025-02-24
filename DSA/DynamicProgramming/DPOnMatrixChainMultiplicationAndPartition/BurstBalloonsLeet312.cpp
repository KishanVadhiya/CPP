// leetcode url - https://leetcode.com/problems/burst-balloons/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
    int recur(int i,int j,vector<int>& nums,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=INT_MIN;
        for(int k=i;k<=j;k++){
            int coins=nums[i-1]*nums[k]*nums[j+1] + recur(i,k-1,nums,dp)+recur(k+1,j,nums,dp);
            maxi=max(maxi,coins);
        }

        return dp[i][j]=maxi;
    }

    int memoization(vector<int>& arr){
        arr.push_back(1);
        arr.insert(arr.begin(),1);
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return recur(1,n-2,arr,dp);

    }

    int tabulation(vector<int>& arr){
        arr.push_back(1);
        arr.insert(arr.begin(),1);
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n));

        for(int i=n-1;i>=1;i--){
            for(int j=i;j<=n-2;j++){
                int maxi=INT_MIN;
                for(int k=i;k<=j;k++){
                    int coins=arr[i-1]*arr[k]*arr[j+1] + dp[i][k-1]+dp[k+1][j];
                    maxi=max(maxi,coins);
                }
                dp[i][j]=maxi;
            }
        }

        return dp[1][n-2];
    }
public:
    int maxCoins(vector<int>& nums) {
        // return memoization(nums);
        return tabulation(nums);
    }
};


int main() {
    Solution sol;
    vector<int> nums = {3, 1, 5, 8};
    cout << "Maximum coins: " << sol.maxCoins(nums) << endl;
    return 0;
}