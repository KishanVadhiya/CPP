// leetcode url - https://leetcode.com/problems/single-element-in-a-sorted-array/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start=0;
        int n=nums.size();
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        int end=n-1;
        int mid;
        while(start<=end){
            mid=start+(end-start)/2;

            if(mid-1>=0 && mid+1<n && (nums[mid]!=nums[mid-1]) && nums[mid]!=nums[mid+1]) return nums[mid];
            else if((mid%2==0 && mid+1<n && nums[mid]==nums[mid+1]) || (mid%2==1 && mid-1>=0 && nums[mid]==nums[mid-1])) start=mid+1;
            else end=mid-1;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << "The single non-duplicate element is: " << sol.singleNonDuplicate(nums) << endl;
    return 0;
}