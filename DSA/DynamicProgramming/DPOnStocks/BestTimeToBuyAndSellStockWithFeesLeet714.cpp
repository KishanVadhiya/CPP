// leetcode url - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
class Solution {
    int fee;
    int recur(int i,vector<int>& arr,bool buy,int n,vector<vector<int>>& dp){
        if(i==n) return dp[i][buy]= 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            return dp[i][buy]=max(-arr[i]-fee+recur(i+1,arr,false,n,dp),recur(i+1,arr,true,n,dp));
        }else{
            return dp[i][buy]=max(arr[i]+recur(i+1,arr,true,n,dp),recur(i+1,arr,false,n,dp));
        }
    }

    int memoization(vector<int>& arr){
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return recur(0,arr,true,n,dp);
    }

    int tabulation(vector<int>& arr){
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(2));

        for(int i=n-1;i>=0;i--){
            for(int j=1;j>=0;j--){
                if(j){
                    dp[i][j]=max(-arr[i]-fee+dp[i+1][0],dp[i+1][1]);
                }else{
                    dp[i][j]=max(arr[i]+dp[i+1][1],dp[i+1][0]);
                }
            }
        }

        return dp[0][1];

    }

    int memoryOpti(vector<int>& arr){
        int n=arr.size();
        int dp[2]={0};

        for(int i=n-1;i>=0;i--){
            int temp[2]={0};
            for(int j=1;j>=0;j--){
                if(j){
                    temp[j]=max(-arr[i]-fee+dp[0],dp[1]);
                }else{
                    temp[j]=max(arr[i]+dp[1],dp[0]);
                }
            }
            memcpy(dp, temp, sizeof(temp));
        }

        return dp[1];
    }

    int memoryOpti2(vector<int>& arr){
        int n=arr.size();
        int aheadBuy=0,aheadNotBuy=0,currBuy=0,currNotBuy=0;

        for(int i=n-1;i>=0;i--){
            currBuy=max(-arr[i]-fee+aheadNotBuy,aheadBuy);
            currNotBuy=max(arr[i]+aheadBuy,aheadNotBuy);

            aheadBuy=currBuy;
            aheadNotBuy=currNotBuy;
        }

        return aheadBuy;
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        this->fee=fee;
        // return memoization(prices);
        // return tabulation(prices);
        // return memoryOpti(prices);
        return memoryOpti2(prices);
        
    }
};


int main() {
    Solution sol;
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << "Maximum profit: " << sol.maxProfit(prices, fee) << endl;
    return 0;
}