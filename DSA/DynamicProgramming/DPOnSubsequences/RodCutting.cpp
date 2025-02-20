// gfg url - https://www.geeksforgeeks.org/problems/rod-cutting0840/1
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    int recur(int idx,int cap,vector<int>& arr,vector<vector<int>>& dp){
        if(idx==0){
           return dp[idx][cap]=arr[0]*(cap/(idx+1));
        }
        if(dp[idx][cap]!=-1) return dp[idx][cap];
        int notpick=recur(idx-1,cap,arr,dp);
        int pick=0;
        if(idx+1<=cap) pick=arr[idx] + recur(idx,cap-idx-1,arr,dp);
        
        return dp[idx][cap]=max(pick,notpick);
    }
    
    int memoisation(vector<int>& arr){
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return recur(n-1,n,arr,dp);
    }
    
    int tabulation(vector<int>& arr){
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n+1));
        for(int j=0;j<=n;j++){
            dp[0][j]=arr[0]*(j);
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int notpick=dp[i-1][j];
                int pick=0;
                if(i+1<=j) pick=arr[i]+dp[i][j-(i+1)];
                dp[i][j]=max(pick,notpick);
            }
        }
        
        return dp[n-1][n];
    }
    
    int memoryOpti1(vector<int>& arr){
        int n=arr.size();
        vector<int> dp(n+1);
        for(int j=0;j<=n;j++){
            dp[j]=arr[0]*(j);
        }
        
        for(int i=1;i<n;i++){
            vector<int> temp(n+1);
            for(int j=0;j<=n;j++){
                int notpick=dp[j];
                int pick=0;
                if(i+1<=j) pick=arr[i]+temp[j-(i+1)];
                temp[j]=max(pick,notpick);
            }
            dp=temp;
        }
        
        return dp[n];
    }
    
    
    
    int memoryOptimization2(vector<int>& arr){
        int n=arr.size();
        vector<int> dp(n+1);
        for(int j=0;j<=n;j++){
            dp[j]=arr[0]*j;
        }
        
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                dp[j]=max(arr[i]+dp[j-(i+1)],dp[j]);
            }
        }
        
        return dp[n];
    }
  public:
    int cutRod(vector<int> &price) {
        // code here
        // return memoisation(price);
        // return tabulation(price);
        // return memoryOpti1(price);
        return memoryOptimization2(price);
    }
};


int main() {
    Solution sol;
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int maxProfit = sol.cutRod(price);
    cout << "Maximum profit: " << maxProfit << endl;
    return 0;
}