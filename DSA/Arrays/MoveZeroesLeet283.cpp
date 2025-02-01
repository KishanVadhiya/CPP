// leetcode url - https://leetcode.com/problems/move-zeroes/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroIdx=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0) 
            swap(nums[i],nums[zeroIdx++]);
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums);
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}