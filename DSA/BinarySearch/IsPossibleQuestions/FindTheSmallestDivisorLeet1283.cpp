// leetcode url - https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int isPossible(vector<int>& arr,int threshold,int ans){
        int sum=0;
        for(auto it:arr){
            sum+=it/ans + (it%ans!=0);
            if(sum>threshold) return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int start=1;
        int end=INT_MIN;

        for(int i=0;i<n;i++){
            end=max(end,nums[i]);
        }

        if(n==threshold) return end;
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;

            if(isPossible(nums,threshold,mid)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }

        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;
    cout << "The smallest divisor is: " << sol.smallestDivisor(nums, threshold) << endl;
    return 0;
}