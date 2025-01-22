// gfg url - https://www.geeksforgeeks.org/problems/rotation4723/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotation
#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    int findKRotation(vector<int> &nums) {
        // Code Here
        int start=0;
        int n=nums.size();
        int end=n-1;
        int mid;
        if(nums[start]<nums[end]) return 0;
        
        while(start<=end){
            mid=start+(end-start)/2;

            if(mid+1<n && nums[mid]>nums[mid+1]) return mid+1;
            else if(nums[mid]>=nums[start]){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }

        return 0;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {15, 18, 2, 3, 6, 12};
    int k = sol.findKRotation(nums);
    cout << "The array is rotated " << k << " times." << endl;
    return 0;
}