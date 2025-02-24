// leetcode url - https://leetcode.com/problems/partition-array-for-maximum-sum/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
    int recur(int i,vector<int>& arr,int k,int n,vector<int> &dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];

        int largest=arr[i];
        int ans=0;
        for(int j=0;j<k && i+j<n;j++){
            largest=max(largest,arr[i+j]);
            int Sum=largest*(j+1) + recur(i+j+1,arr,k,n,dp);
            ans=max(ans,Sum);
        }

        return dp[i]=ans;
    }

    int memoization(vector<int>& arr,int k){
        int n=arr.size();
        vector<int> dp(n,-1);
        return recur(0,arr,k,n,dp);
    }

    int tabulation(vector<int>& arr,int k){
        int n=arr.size();
        vector<int> dp(n+1,0);

        for(int i=n-1;i>=0;i--){
            int largest=arr[i];
            int ans=0;

            for(int j=0;j<k&& i+j<n;j++){
                largest=max(largest,arr[i+j]);
                int sum=largest*(j+1) + dp[i+j+1];
                ans=max(ans,sum);
            }

            dp[i]=ans;
        }

        return dp[0];
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // return memoization(arr,k);
        return tabulation(arr,k);
    }
};


int main() {
    Solution sol;
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    cout << "Maximum sum after partitioning: " << sol.maxSumAfterPartitioning(arr, k) << endl;
    return 0;
}