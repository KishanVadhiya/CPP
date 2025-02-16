// leetcode url - https://leetcode.com/problems/house-robber/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int rob(vector<int>& nums) {
            int n=nums.size();
            if(n==1) return nums[0];
            if(n==2) return max(nums[1],nums[0]);
            int a=nums[0];
            int b=nums[1];
            int c=nums[2]+nums[0];
            for(int i=3;i<n;i++){
                int sum=max(b,a)+nums[i];
                a=b;
                b=c;
                c=sum;
            }
    
            return max(b,c);
        }
    };


    int main() {
        Solution solution;
        vector<int> nums = {2, 7, 9, 3, 1};
        cout << "Maximum amount that can be robbed: " << solution.rob(nums) << endl;
        return 0;
    }