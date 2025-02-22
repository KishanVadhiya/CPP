// leetcode url - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
#include<iostream>
#include<vector>
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

    int memoization(vector<int>& arr,int capacity){
        int n=arr.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(capacity+1,-1)));
        return recur(0,true,capacity,n,arr,dp);
    }

    int tabulation(vector<int>& arr,int capacity){
        int n=arr.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(capacity+1)));
        
        for(int i=n-1;i>=0;i--){
            for(int buy=1;buy>=0;buy--){
                for(int cap=capacity;cap>=1;cap--){
                    if(buy){
                        dp[i][buy][cap]=max(-arr[i]+dp[i+1][false][cap],dp[i+1][true][cap]);
                    }else{
                        dp[i][buy][cap]=max(arr[i]+dp[i+1][true][cap-1],dp[i+1][false][cap]);
                    }
                }
            }
        }

        return dp[0][1][capacity];
    }

    int memoryOpti(vector<int>& arr,int capacity){
        int n=arr.size();
        vector<vector<int>> dp(2,vector<int>(capacity+1)),temp(2,vector<int>(capacity+1));

        for(int i=n-1;i>=0;i--){
            for(int buy=1;buy>=0;buy--){
                for(int cap=capacity;cap>=1;cap--){
                    if(buy) temp[buy][cap]=max(-arr[i]+dp[false][cap],dp[true][cap]);
                    else temp[buy][cap]=max(arr[i]+dp[true][cap-1],dp[false][cap]);
                }
            }
            dp=temp;
        }

        return dp[true][capacity];
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        // return memoization(prices,k);
        // return tabulation(prices,k);
        return memoryOpti(prices,k);
    }
};

int main() {
    Solution sol;
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    int k = 2;
    cout << "Maximum profit: " << sol.maxProfit(k, prices) << endl;
    return 0;
}