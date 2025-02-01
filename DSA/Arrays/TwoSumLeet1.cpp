// leetcode url - https://leetcode.com/problems/two-sum/
#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(umap.find(target-nums[i])!=umap.end()) return vector<int>{umap[target-nums[i]],i};
            umap[nums[i]]=i;
        }
        return vector<int>(); 
    }
};


int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = solution.twoSum(nums, target);
    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }
    return 0;
}