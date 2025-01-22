// leetcode url - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0;
        int n=nums.size();
        int end=n-1;
        int mid;

        while(start<=end){
            mid=start+(end-start)/2;

            if(mid+1<n && nums[mid]>nums[mid+1]) return nums[mid+1];
            else if(nums[mid]>=nums[start]){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }

        return nums[0];
    }
};


int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << "The minimum element is: " << sol.findMin(nums) << endl;
    return 0;
}