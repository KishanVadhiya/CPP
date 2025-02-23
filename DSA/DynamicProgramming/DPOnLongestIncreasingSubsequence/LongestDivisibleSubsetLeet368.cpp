// leetcode url - https://leetcode.com/problems/largest-divisible-subset/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    vector<int> memoryOpti2(vector<int>& arr){
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<int> dp(n,1);
        vector<int> mp(n,-1);
        // for(int i=0;i<n;i++) mp[i]=i;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0 && dp[i]<=dp[j]){
                    mp[i]=j;
                    dp[i]=dp[j]+1;
                }
            }
        }

        vector<int> ans;
        int maxIdx=max_element(dp.begin(),dp.end())-dp.begin();
        // ans.push_back(arr[maxIdx]);
        while(maxIdx!=-1){
            ans.push_back(arr[maxIdx]);
            maxIdx=mp[maxIdx];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        return memoryOpti2(nums);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 8, 9};
    vector<int> result = sol.largestDivisibleSubset(nums);
    
    cout << "Largest Divisible Subset: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}