// leetcode url - https://leetcode.com/problems/max-consecutive-ones-iii/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int start=0;
            int end=0;
            int ans=0;
            int n=nums.size();
            while(end<n){
                if(nums[end]==1){
                    end++;
                }else{
                    if(k>0){
                        end++;
                        k--;
                    }else{
                        while(k==0){
                            if(nums[start++]==0){
                                k++;
                            }
                        }
                    }
                }
                ans=max(ans,end-start);
            }
    
            return ans;
        }
    };


    int main() {
        Solution sol;
        vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 0, 1, 1};
        int k = 2;
        int result = sol.longestOnes(nums, k);
        cout << "The maximum number of consecutive 1s is: " << result << endl;
        return 0;
    }