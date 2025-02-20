// gfg url - https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=knapsack-with-duplicate-items

#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
    int recur(int idx,int cap,vector<int>& val,vector<int>& wt,vector<vector<int>>& dp){
        if(idx==0){
            return dp[idx][cap]=val[0]*(cap/wt[0]);
        }
        if(dp[idx][cap]!=-1) return dp[idx][cap];
        int notpick=recur(idx-1,cap,val,wt,dp);
        int pick=INT_MIN;
        if(wt[idx]<=cap) pick=val[idx]+recur(idx,cap-wt[idx],val,wt,dp);
        
        return dp[idx][cap]=max(notpick,pick);
    }
    int memoization(vector<int>& val,vector<int>& wt,int capacity){
        int n=val.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
        return recur(n-1,capacity,val,wt,dp);
    }
    
    int tabulation(vector<int>& val,vector<int>& wt,int cap){
        int n=val.size();
        vector<vector<int>> dp(n,vector<int>(cap+1));
        
        for(int j=0;j<=cap;j++){
            dp[0][j]=val[0]*(j/wt[0]);
        }
        
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=cap;j++){
                int notpick=dp[i-1][j];
                int pick=INT_MIN;
                if(j>=wt[i]) pick=val[i]+dp[i][j-wt[i]];
                
                dp[i][j]=max(pick,notpick);
            }
        }
        
        return dp[n-1][cap];
    }
    
    int memoryOpti(vector<int>& val,vector<int>& wt,int cap){
        int n=val.size();
        vector<int> dp(cap+1);
        for(int j=0;j<=cap;j++){
            dp[j]=val[0]*(j/wt[0]);
        }
        
        for(int i=1;i<n;i++){
            vector<int> temp(cap+1);
            for(int j=0;j<=cap;j++){
                int notpick=dp[j];
                int pick=INT_MIN;
                if(j>=wt[i]) pick=val[i]+temp[j-wt[i]];
                
                temp[j]=max(pick,notpick);
            }
            dp=temp;
        }
        
        return dp[cap];
    }
    
    
    int memoryOpti2(vector<int>& val,vector<int>& wt,int cap){
        int n=val.size();
        vector<int> dp(cap+1);
        for(int j=0;j<=cap;j++){
            dp[j]=val[0]*(j/wt[0]);
        }
        
        for(int i=1;i<n;i++){
            
            for(int j=wt[i];j<=cap;j++){
                dp[j]=max(val[i]+dp[j-wt[i]],dp[j]);
            }
        }
        
        return dp[cap];
    }
    
    
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        // return memoization(val,wt,capacity);
        // return tabulation(val,wt,capacity);
        return memoryOpti2(val,wt,capacity);
        
    }
};


int main() {
    vector<int> val = {10, 40, 50, 70};
    vector<int> wt = {1, 3, 4, 5};
    int capacity = 8;
    
    Solution sol;
    cout << "Maximum value in Knapsack = " << sol.knapSack(val, wt, capacity) << endl;
    
    return 0;
}