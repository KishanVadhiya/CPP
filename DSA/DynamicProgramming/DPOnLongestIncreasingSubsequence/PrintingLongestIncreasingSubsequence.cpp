// gfg url - https://www.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=printing-longest-increasing-subsequence

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    vector<int> memoryOpti2(vector<int>& arr){
        int n=arr.size();
        vector<int> dp(n,1);
        vector<int> mp(n);
        for(int i=0;i<n;i++) mp[i]=i;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j] && dp[i]<=dp[j]){
                    dp[i]=dp[j]+1;
                    mp[i]=j;
                }
            }
        }
        
        int maxIdx=max_element(dp.begin(),dp.end())-dp.begin();
        
        vector<int> ans;
        ans.push_back(arr[maxIdx]);
        while(maxIdx!=mp[maxIdx]){
            maxIdx=mp[maxIdx];
            ans.push_back(arr[maxIdx]);
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        // return *max_element(dp.begin(),dp.end());
    }
    
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        return memoryOpti2(arr);
        
    }
};

int main() {
    Solution sol;
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n = arr.size();
    
    vector<int> lis = sol.longestIncreasingSubsequence(n, arr);
    
    cout << "The Longest Increasing Subsequence is: ";
    for(int i : lis) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}