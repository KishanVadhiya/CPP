// leetcode url  - https://leetcode.com/problems/sort-colors/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int idx1=0;
        int idx0=0;
        int idx2=nums.size()-1;

        while(idx1<=idx2){
            if(nums[idx1]==2){
                swap(nums[idx1],nums[idx2--]);
            }else if(nums[idx1]==0){
                swap(nums[idx0++],nums[idx1++]);
            }else{
                idx1++;
            }
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    solution.sortColors(nums);

    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}