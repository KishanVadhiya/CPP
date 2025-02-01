// leetcode url - https://leetcode.com/problems/maximum-subarray/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int sum=0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans=max(ans,sum);
            sum=max(0,sum);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = sol.maxSubArray(nums);
    cout << "Maximum subarray sum is " << result << endl;
    return 0;
}