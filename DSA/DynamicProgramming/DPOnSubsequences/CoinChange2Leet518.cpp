// leetcode url - https://leetcode.com/problems/coin-change-ii/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    int recur(int idx,int amt,vector<int>& arr,vector<vector<int>>& dp){
        if(idx==0){
            return dp[idx][amt]=(amt%arr[idx]==0);
        }
        if(dp[idx][amt]!=-1) return dp[idx][amt];
        int notpick=recur(idx-1,amt,arr,dp);
        int pick=0;
        if(arr[idx]<=amt) pick=recur(idx,amt-arr[idx],arr,dp);

        return dp[idx][amt]=(pick+notpick);
    }

    int memoization(int amt,vector<int>& arr){
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(amt+1,-1));
        return recur(n-1,amt,arr,dp);
    }

    int tabulation(int amt,vector<int>& arr){
        int n=arr.size();
        vector<vector<long>> dp(n,vector<long>(amt+1));

        for(int j=0;j<=amt;j++){
            dp[0][j]=(j%arr[0]==0);
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=amt;j++){
                int notpick=dp[i-1][j];
                int pick=0;
                if(arr[i]<=j) pick=dp[i][j-arr[i]];
                dp[i][j]=1L*pick+notpick;
            }
        }

        return dp[n-1][amt];
    }

    int memoryOpt(int amt,vector<int>& arr){
        int n=arr.size();
        vector<long> dp(amt+1);

        for(int j=0;j<=amt;j++){
            dp[j]=(j%arr[0]==0);
        }

        for(int i=1;i<n;i++){
            vector<long> temp(amt+1);
            for(int j=0;j<=amt;j++){
                int notpick=dp[j];
                int pick=0;
                if(arr[i]<=j) pick=temp[j-arr[i]];
                temp[j]=1L*pick+notpick;
            }
            dp=temp;
        }

        return dp[amt];
    }

    int memoryOpt2(int amt,vector<int>& coins){
        vector<unsigned int> dp(amt+1);
        dp[0]=1;
        for(auto coin:coins){
            for(int j=coin;j<=amt;j++){
                dp[j]+=dp[j-coin];
            }
        }

        return dp[amt];
    }

public:
    int change(int amount, vector<int>& coins) {
        // return memoization(amount,coins);
        // return tabulation(amount,coins);
        // return memoryOpt(amount,coins);
        return memoryOpt2(amount,coins);
    }
};

int main() {
    Solution sol;
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    cout << "Number of ways to make change: " << sol.change(amount, coins) << endl;
    return 0;
}