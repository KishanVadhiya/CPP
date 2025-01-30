// leetcode url - https://leetcode.com/problems/subsets-ii/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    vector<vector<int>> ans;
    void recur(vector<int>& nums,int start,int &end,vector<int> &temp){
        ans.push_back(temp);
        for(int i=start;i<=end;i++){
            if((i>start) && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            recur(nums,i+1,end,temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        int end=nums.size()-1;
        recur(nums,0,end,temp);
        return ans;
    }
};



int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = sol.subsetsWithDup(nums);

    cout << "Subsets with duplicates:" << endl;
    for (const auto& subset : result) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}