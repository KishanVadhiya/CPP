// leetcode url - https://leetcode.com/problems/find-peak-element/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;

        int start=0,end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;

            if(mid-1>=0 && mid+1<n && nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            else if((mid-1>=0 && nums[mid]>nums[mid-1]) || (mid+1<n && nums[mid]<nums[mid+1])){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    int peakIndex = sol.findPeakElement(nums);
    cout << "Peak element index: " << peakIndex << endl;
    return 0;
}
