// leetcode url - https://leetcode.com/problems/partition-equal-subset-sum/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    bool recur(int i,int target,vector<int>& arr,vector<vector<int>>& dp){
        if(target==0) return dp[i][target]=true;

        if(i==0) return dp[i][target]=(target==arr[0]);

        if(dp[i][target]!=-1) return dp[i][target];

        bool notPick=recur(i-1,target,arr,dp);

        bool pick=false;
        if(target>=arr[i]) pick=recur(i-1,target-arr[i],arr,dp);

        return dp[i][target]=(pick || notPick);
    }

    bool memoization(vector<int>& arr,int target,int n){
        vector<vector<int>> dp(n,vector<int>(target+1,-1));

        return recur(n-1,target,arr,dp);
    }

    bool tabulation(vector<int>& arr,int target,int n){
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }

        if(arr[0]<=target) dp[0][arr[0]]=1;

        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool notPick=dp[i-1][j];
                bool pick=false;
                if(j>=arr[i]) pick=dp[i-1][j-arr[i]];

                dp[i][j]=pick|| notPick;
            }
        }

        return dp[n-1][target];
    }

    bool memoryOptimization(vector<int>& arr,int target,int n){
        vector<int> dp(target+1,0);
        dp[0]=1;
        if(target>=arr[0])  dp[arr[0]]=1;

        for(int i=1;i<n;i++){
            vector<int> temp(target+1,0);
            temp[0]=1;
            for(int j=1;j<=target;j++){
                bool notPick=dp[j];
                bool pick=false;
                if(j>=arr[i]) pick=dp[j-arr[i]];
                temp[j]=pick || notPick;
            }
            dp=temp;
        }

        return dp[target];
    }
public:
    bool canPartition(vector<int>& nums) {
        int S=0;
        for(auto it:nums) S+=it;
        int n=nums.size();
        if(S%2) return false;

        // return memoization(nums,S/2,n);
        // return tabulation(nums,S/2,n);
        return memoryOptimization(nums,S/2,n);
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 5, 11, 5};
    if(sol.canPartition(nums)) {
        cout << "Can partition" << endl;
    } else {
        cout << "Cannot partition" << endl;
    }
    return 0;
}