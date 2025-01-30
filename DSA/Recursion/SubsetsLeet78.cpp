// leetcode url - https://leetcode.com/problems/subsets/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    vector<vector<int>> ans;
    void recur(vector<int> &arr,int start,vector<int> &nums){
        ans.push_back(arr);
        int n=nums.size();
        for(int i=start;i<n;i++){
            arr.push_back(nums[i]);
            recur(arr,i+1,nums);
            arr.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        recur(temp,0,nums);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.subsets(nums);

    cout << "Subsets:" << endl;
    for (const auto& subset : result) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}