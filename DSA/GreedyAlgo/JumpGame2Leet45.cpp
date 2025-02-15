// leetcode url - https://leetcode.com/problems/jump-game-ii/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int jump(vector<int>& nums) {
            int left=1;
            int right=nums[0];
            int jumps=0;
            int n=nums.size();
            while(left<n){
                jumps++;
                int end=right;
                while(left<n && left<=end){
                    right=max(right,nums[left]+left);
                    left++;
                }
            }
    
            return jumps;
        }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << "Minimum number of jumps: " << sol.jump(nums) << endl;
    return 0;
}