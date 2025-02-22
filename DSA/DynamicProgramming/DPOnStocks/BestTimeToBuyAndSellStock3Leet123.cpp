// leetcode url - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
    int recur(int i,bool buy,int cap,int n,vector<int>& arr,vector<vector<vector<int>>> &dp){
        if(i==n || cap==0) return dp[i][buy][cap]=0;
        // if(cap==0) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        if(buy){
            return dp[i][buy][cap]=max(-arr[i]+recur(i+1,false,cap,n,arr,dp),recur(i+1,true,cap,n,arr,dp));
        }else{
            return dp[i][buy][cap]=max(arr[i]+recur(i+1,true,cap-1,n,arr,dp),recur(i+1,false,cap,n,arr,dp));
        }
    }

    int memoization(vector<int>& arr){
        int n=arr.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return recur(0,true,2,n,arr,dp);
    }

    int tabulation(vector<int>& arr){
        int n=arr.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3)));
        
        for(int i=n-1;i>=0;i--){
            for(int buy=1;buy>=0;buy--){
                for(int cap=2;cap>=1;cap--){
                    if(buy){
                        dp[i][buy][cap]=max(-arr[i]+dp[i+1][false][cap],dp[i+1][true][cap]);
                    }else{
                        dp[i][buy][cap]=max(arr[i]+dp[i+1][true][cap-1],dp[i+1][false][cap]);
                    }
                }
            }
        }

        return dp[0][1][2];
    }

    int memoryOpti(vector<int>& arr){
        int n=arr.size();
        vector<vector<int>> dp(2,vector<int>(3)),temp(2,vector<int>(3));

        for(int i=n-1;i>=0;i--){
            for(int buy=1;buy>=0;buy--){
                for(int cap=2;cap>=1;cap--){
                    if(buy) temp[buy][cap]=max(-arr[i]+dp[false][cap],dp[true][cap]);
                    else temp[buy][cap]=max(arr[i]+dp[true][cap-1],dp[false][cap]);
                }
            }
            dp=temp;
        }

        return dp[true][2];
    }

    int optimalGreedy(vector<int>& arr){
        int n=arr.size();
        int t1_buy=INT_MAX,t2_buy=INT_MAX,t1_sell=0,t2_sell=0;

        for(int i=0;i<n;i++){
            t1_buy=min(t1_buy,arr[i]);
            t1_sell=max(t1_sell,arr[i]-t1_buy);

            t2_buy=min(t2_buy,arr[i]-t1_sell); // reinvesting the profit
            t2_sell=max(t2_sell,arr[i]-t2_buy); // total profit
        }

        return t2_sell;
    }
public:
    int maxProfit(vector<int>& prices) {
        // return memoization(prices);
        // return tabulation(prices);
        // return memoryOpti(prices);
        return optimalGreedy(prices);
    }
};


int main() {
    Solution sol;
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout << "Maximum Profit: " << sol.maxProfit(prices) << endl;
    return 0;
}