#include<iostream>
#include<vector>
using namespace std;
class Solution {
    int upper=-1,lower=-1;

    void upperBound(vector<int>& nums,int st,int end,int target){
        if(st<=end){
            int mid=st+(end-st)/2;
            if(nums[mid]>target){
                upperBound(nums,st,mid-1,target);
            }else{
                upper=mid;
                upperBound(nums,mid+1,end,target);
            }
        }
    }

    void lowerBound(vector<int> &nums,int st,int end,int target){
        if(st<=end){
            int mid=st+(end-st)/2;
            if(nums[mid]<target){
                lowerBound(nums,mid+1,end,target);
            }else{
                lower=mid;
                lowerBound(nums,st,mid-1,target);
            }
        }
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        upperBound(nums,0,nums.size()-1,target);
        lowerBound(nums,0,nums.size()-1,target);

        return vector<int>{lower,upper};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = sol.searchRange(nums, target);

    cout << "Lower Bound: " << result[0] << ", Upper Bound: " << result[1] << endl;

    return 0;
}