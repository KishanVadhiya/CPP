// leetcode url - https://leetcode.com/problems/subarrays-with-k-different-integers/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    int subarraysWithLessThanK(vector<int>& nums,int k){
        if(k==0) return 0;
        int start=0;
        int end=0;
        int ans=0;
        int n=nums.size();
        vector<int> cnt(n+1);
        int distinct=0;

        while(end<n){
            if(cnt[nums[end]]>0) cnt[nums[end]]++;
            if(cnt[nums[end]]==0){
                cnt[nums[end]]++;
                k--;
                
                while(k<0){
                    cnt[nums[start]]--;
                    if(cnt[nums[start++]]==0) k++;
                }
            }

            ans+=end-start+1;
            end++;
        }

        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithLessThanK(nums,k)-subarraysWithLessThanK(nums,k-1);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    cout << sol.subarraysWithKDistinct(nums, k) << endl;
    return 0;
}