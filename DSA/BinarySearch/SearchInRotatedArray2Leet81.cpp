// leetcode url - https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start=0;
        int n=nums.size();
        int end=n-1;

        while(start<=end){
            int mid=start+(end-start)/2;

            if(nums[mid]==target) return true;
            else if(nums[mid]==nums[start] && nums[mid]==nums[end]){
                start++;
                end--;
            }
            else if(nums[start]<=nums[mid]){
                if(target>=nums[start] && target<nums[mid]){
                    end=mid-1;
                }else{
                    start=mid+1;
                }
            }else{
                if(target>nums[mid] && target<=nums[end]){
                    start=mid+1;
                }else{
                    end=mid-1;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    if(sol.search(nums, target)) {
        cout << "Target found in the array." << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}