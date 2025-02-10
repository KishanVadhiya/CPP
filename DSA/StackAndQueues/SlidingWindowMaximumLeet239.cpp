// leetcode url - https://leetcode.com/problems/sliding-window-maximum/
#include<iostream>
#include<deque>
#include<vector>
using namespace std;
class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            deque<int> dq;
            vector<int> ans;
            int n=nums.size();
            for(int i=0;i<k;i++){
    
                    while(!dq.empty() && nums[dq.back()]<nums[i]){
                        dq.pop_back();
                    }
                    dq.push_back(i);
            }
    
            ans.push_back(nums[dq.front()]);
    
            for(int i=k;i<n;i++){
                if(i-dq.front()==k) dq.pop_front();
    
                while(!dq.empty() && nums[dq.back()]<nums[i]){
                    dq.pop_back();
                }
                dq.push_back(i);
                ans.push_back(nums[dq.front()]);
            }
            return ans;
        }
    };


    int main() {
        Solution sol;
        vector<int> nums = {1,3,-1,-3,5,3,6,7};
        int k = 3;
        vector<int> result = sol.maxSlidingWindow(nums, k);

        for(int i : result) {
            cout << i << " ";
        }
        cout << endl;

        return 0;
    }