// leetcode url - https://leetcode.com/problems/rearrange-array-elements-by-sign/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int posStart=0;
        int negStart=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[posStart]=nums[i];
                posStart+=2;
            }else{
                ans[negStart]=nums[i];
                negStart+=2;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> result = sol.rearrangeArray(nums);

    cout << "Rearranged array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}