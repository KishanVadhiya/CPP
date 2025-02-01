// leetcode url - https://leetcode.com/problems/next-permutation/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=-1;
        int n=nums.size();
        for(int k=0;k<n-1;k++){
            if(nums[k]<nums[k+1]){
                i=k;
                // j=k+1;
            }
        }
        if(i!=-1){
            for(int k=n-1;k>i;k--){
                if(nums[k]>nums[i]){
                    swap(nums[k],nums[i]);
                    break;
                }
            }
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    sol.nextPermutation(nums);
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}