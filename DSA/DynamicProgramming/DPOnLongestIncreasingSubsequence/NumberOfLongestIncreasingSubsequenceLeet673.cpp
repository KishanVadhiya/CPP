// leetcode url - https://leetcode.com/problems/number-of-longest-increasing-subsequence/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
    int memoryOpti2(vector<int>& arr){
        int n=arr.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        int ans=0;
        int maxi=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    cnt[i]=cnt[j];
                }else if(dp[i]==dp[j]+1){
                    cnt[i]+=cnt[j];
                }
            }
            if(maxi<dp[i]){
                maxi=dp[i];
                ans=cnt[i];
            }else if(maxi==dp[i]){
                ans+=cnt[i];
            }
        }

        // for(auto it:dp){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // for(auto it:cnt){
        //     cout<<it<<" ";
        // }
        // cout<<endl;

        if(maxi==1) ans++; // for cases like [2,2,2,2,2] idx 0 will not be considered for length 1

        return ans;
    }
public:
    int findNumberOfLIS(vector<int>& nums) {
        return memoryOpti2(nums);
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 4, 7};
    cout << "Number of Longest Increasing Subsequences: " << sol.findNumberOfLIS(nums) << endl;
    return 0;
}