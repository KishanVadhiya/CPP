// leetcode url - https://leetcode.com/problems/house-robber-ii/description/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int rob1(vector<int>& nums,int start,int end) {
            int n=nums.size();
            if(n==1) return nums[0];
            if(n==2) return max(nums[1],nums[0]);
            int a=nums[start];
            int b=nums[start+1];
            int c=nums[start+2]+nums[start];
            for(int i=3;i<=end;i++){
                int sum=max(b,a)+nums[i];
                a=b;
                b=c;
                c=sum;
            }
    
            return max(b,c);
        }
        int rob(vector<int>& nums) {
            int n=nums.size();
            if(n<4){
                int maxx=0;
                for(auto it:nums){
                    maxx=max(maxx,it);
                }
                return maxx;
            }
            
            return max(rob1(nums,0,n-2),rob1(nums,1,n-1));
            
        }
    };

    int main() {
        Solution solution;
        vector<int> nums = {2, 3, 2};
        cout << "Maximum amount that can be robbed: " << solution.rob(nums) << endl;
        return 0;
    }