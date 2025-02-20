// leetcode url - https://leetcode.com/problems/coin-change/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    int recur(int idx,int amount,vector<int>& arr,vector<vector<int>>& dp){
        if(idx==0){
            if(amount%arr[0]==0) return dp[idx][amount]=amount/arr[0];
            else return dp[idx][amount]=1e9;
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int notpick=recur(idx-1,amount,arr,dp);

        int pick=1e9;

        if(arr[idx]<=amount) pick=1+recur(idx,amount-arr[idx],arr,dp);

        return dp[idx][amount]=min(pick,notpick);
    }

    int memoization(vector<int>& arr,int amount){
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=recur(n-1,amount,arr,dp);
        if(ans>=1e9) return -1;
        return ans;
    }

    int tabulation(vector<int>& arr,int amount){
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(amount+1));
        for(int i=0;i<=amount;i++){
            if(i%arr[0]==0) dp[0][i]=i/arr[0];
            else dp[0][i]=1e9;
        }


        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int notpick=dp[i-1][j];

                int pick=1e9;

                if(arr[i]<=j) pick=1+dp[i][j-arr[i]];

                dp[i][j]=min(pick,notpick);
            }
        }

        if(dp[n-1][amount]>=1e9) return -1;
        else return dp[n-1][amount];
    }

    int memoryOptimization1(vector<int>& arr,int amount){
        int n=arr.size();
        vector<int> dp(amount+1);
        for(int i=0;i<=amount;i++){
            if(i%arr[0]==0) dp[i]=i/arr[0];
            else dp[i]=1e9;
        }

        for(int i=1;i<n;i++){
            vector<int> temp(amount+1);
            for(int j=0;j<=amount;j++){
                int notpick=dp[j];
                int pick=1e9;
                if(arr[i]<=j) pick=1+temp[j-arr[i]];
                temp[j]=min(pick,notpick);
            }
            dp=temp;
        }

        return (dp[amount]>=1e9)?-1:dp[amount];
    }

    int memoryOptimization2(vector<int>& coins,int amount){
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;

        for(int i=1;i<=amount;i++){
            for(auto coin:coins){
                if(i>=coin) dp[i]=min(dp[i],1+dp[i-coin]);
            }
        }

        return (dp[amount]>amount)?-1:dp[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        // sort(coins.begin(),coins.end());
        // return memoization(coins,amount);
        // return tabulation(coins,amount);
        // return memoryOptimization1(coins,amount);
        return memoryOptimization2(coins,amount);
    }
};


int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int result = sol.coinChange(coins, amount);
    cout << "Minimum coins required: " << result << endl;
    return 0;
}