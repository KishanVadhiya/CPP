// leet url - https://leetcode.com/problems/count-number-of-nice-subarrays/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int numberOfSubarraysLessThanK(vector<int>& nums,int k){
            if(k<0) return 0;
            int start=0;
            int end=0;
            int cnt=0;
            int n=nums.size();
            while(end<n){
                if(nums[end]%2==1) k--;
    
                while(k<0){
                    if(nums[start++]%2==1) k++;
                }
                cnt+=end-start+1;
                end++;
    
            }
            return cnt;
        }
        int numberOfSubarrays(vector<int>& nums, int k) {
            return numberOfSubarraysLessThanK(nums,k) - numberOfSubarraysLessThanK(nums,k-1);
        }
    };


    int main() {
        Solution sol;
        vector<int> nums = {1, 1, 2, 1, 1};
        int k = 3;
        int result = sol.numberOfSubarrays(nums, k);
        cout << "Number of nice subarrays: " << result << endl;
        return 0;
    }