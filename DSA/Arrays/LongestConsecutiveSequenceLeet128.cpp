// leetcode url - https://leetcode.com/problems/longest-consecutive-sequence/
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans =0;
        unordered_set<int>seen(nums.begin(),nums.end());
        int n=seen.size();
        for(int num:nums){
            if(seen.count(num-1)){
                continue;
            }
        int len=1;
        while(seen.count(++num))
            ++len;
            ans= max(ans,len); 
            if(ans>n/2) break;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Longest consecutive sequence length: " << sol.longestConsecutive(nums) << endl;
    return 0;
}