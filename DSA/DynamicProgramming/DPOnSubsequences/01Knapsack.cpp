// gfg url - https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    int recur(int i,int cap,vector<int>& wt,vector<int>& val,vector<vector<int>>& dp){
        if(i==0){
            if(cap>=wt[i]){
                return dp[i][cap]=val[i];
            }else{
                return dp[i][cap]=0;
            }
        }
        if(dp[i][cap]!=-1) return dp[i][cap];
        int notPick=recur(i-1,cap,wt,val,dp);
        int pick=0;
        if(wt[i]<=cap) pick=val[i]+recur(i-1,cap-wt[i],wt,val,dp);
        
        return dp[i][cap]=max(pick,notPick);
        }
    int memoization(int capacity,vector<int>& val,vector<int>& wt){
        int n=val.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
        return recur(n-1,capacity,wt,val,dp);
    }
    
    int tabulation(int capacity,vector<int>& val,vector<int>& wt){
        int n=val.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1));
        for(int j=0;j<=capacity;j++){
            if(wt[0]<=j){
                dp[0][j]=val[0];
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<=capacity;j++){
                int notPick=dp[i-1][j];
                int pick=0;
                if(wt[i]<=j) pick=val[i]+dp[i-1][j-wt[i]];
                
                dp[i][j]=max(pick,notPick);
            }
        }
        
        // for(auto it:dp){
        //     for(auto i:it){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return dp[n-1][capacity];
        
    }
    
    int memoryOptimization(int capacity,vector<int>& val,vector<int>& wt){
        int n=val.size();
        vector<int> dp(capacity+1);
        for(int j=0;j<=capacity;j++){
            if(wt[0]<=j){
                dp[j]=val[0];
            }
        }
        
        for(int i=1;i<n;i++){
            vector<int> temp(capacity+1);
            for(int j=1;j<=capacity;j++){
                int notPick=dp[j];
                int pick=0;
                if(wt[i]<=j) pick=val[i] + dp[j-wt[i]];
                
                temp[j]=max(pick,notPick);
            }
            dp=temp;
        }
        return dp[capacity];
    }
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        // code here
        // return memoization(capacity,val,wt);
        // return tabulation(capacity,val,wt);
        return memoryOptimization(capacity,val,wt);
    }
};


int main() {
    Solution sol;
    int capacity = 50;
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    
    cout << "Maximum value in Knapsack = " << sol.knapSack(capacity, val, wt) << endl;
    
    return 0;
}