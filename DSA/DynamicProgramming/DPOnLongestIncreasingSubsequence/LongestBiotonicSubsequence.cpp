// gfg url - https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> memoryOpti2(vector<int>& arr){
    int n=arr.size();
    vector<int> dp(n,1);

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j] && dp[i]<=dp[j]){
                dp[i]=dp[j]+1;
            }
        }
    }

    return dp;
}
class Solution {
public:
int LongestBitonicSequence(int n, vector<int> &nums) {
    // code here
    vector<int> dp1=memoryOpti2(nums);
    reverse(nums.begin(),nums.end());
    vector<int> dp2=memoryOpti2(nums);
    reverse(dp2.begin(),dp2.end());
    
    int ans=0;
    
    for(int i=0;i<n;i++){
        if(dp1[i]!=1 && dp2[i]!=1){
            ans=max(ans,dp1[i]+dp2[i]-1);
        }
    }
    
    return ans;
}
};


int main() {
    Solution sol;
    vector<int> nums = {1, 11, 2, 10, 4, 5, 2, 1};
    int n = nums.size();
    cout << "Length of Longest Bitonic Subsequence is: " << sol.LongestBitonicSequence(n, nums) << endl;
    return 0;
}