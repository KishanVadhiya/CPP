// leetcode url - https://leetcode.com/problems/missing-number/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=(n*(n+1))/2;

        for(auto it:nums){
            sum-=it;
        }

        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 0, 1};
    cout << "The missing number is: " << sol.missingNumber(nums) << endl;
    return 0;
}