// leetcode url - https://leetcode.com/problems/search-in-rotated-sorted-array/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int n=nums.size();
        int end=n-1;

        while(start<=end){
            int mid=start+(end-start)/2;

            if(nums[mid]==target) return mid;
            else if(nums[start]<=nums[mid]){
                if(target>=nums[0] && target<nums[mid]){
                    end=mid-1;
                }else{
                    start=mid+1;
                }
            }else{
                if(target>nums[mid] && target<=nums[n-1]){
                    start=mid+1;
                }else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int result = sol.search(nums, target);
    cout << "Index of " << target << " is: " << result << endl;
    return 0;
}