// leetcode url - https://leetcode.com/problems/jump-game/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int n=nums.size();
            int maxReachable=0;
    
            for(int i=0;i<n;i++){
                if(i>maxReachable) return false;
                maxReachable=max(maxReachable,nums[i]+i);
            }
    
            return true;
        }
    };

    int main() {
        Solution sol;
        vector<int> nums = {2, 3, 1, 1, 4};
        bool result = sol.canJump(nums);
        cout << (result ? "Can jump to the end" : "Cannot jump to the end") << endl;
        return 0;
    }