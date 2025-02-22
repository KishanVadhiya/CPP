// leetcode url - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    int recur(int i,vector<int>& arr,bool buy,int n,vector<vector<int>>& dp){
        if(i>=n) return dp[n][buy]= 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            return dp[i][buy]=max(-arr[i]+recur(i+1,arr,false,n,dp),recur(i+1,arr,true,n,dp));
        }else{
            return dp[i][buy]=max(arr[i]+recur(i+2,arr,true,n,dp),recur(i+1,arr,false,n,dp));
        }
    }

    int memoization(vector<int>& arr){
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return recur(0,arr,true,n,dp);
    }

    int tabulation(vector<int>& arr){
        int n=arr.size();
        vector<vector<int>> dp(n+2,vector<int>(2));

        for(int i=n-1;i>=0;i--){
            for(int j=1;j>=0;j--){
                if(j){
                    dp[i][j]=max(-arr[i]+dp[i+1][0],dp[i+1][1]);
                }else{
                    dp[i][j]=max(arr[i]+dp[i+2][1],dp[i+1][0]);
                }
            }
        }

        return dp[0][1];

    }

    int memoryOpti(vector<int>& arr){
        int n=arr.size();
        vector<int> prev(2);
        vector<int> dp(2);

        for(int i=n-1;i>=0;i--){
            vector<int> temp(2);
            for(int j=1;j>=0;j--){
                if(j){
                    temp[j]=max(-arr[i]+dp[0],dp[1]);
                }else{
                    temp[j]=max(arr[i]+prev[1],dp[0]);
                }
            }
            prev=dp;
            dp=temp;

        }

        return dp[1];
    }

public:
    int maxProfit(vector<int>& prices) {
        // return memoization(prices);
        // return tabulation(prices);
        return memoryOpti(prices);
    }
};


int main() {
    Solution sol;
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << "Max Profit: " << sol.maxProfit(prices) << endl;
    return 0;
}