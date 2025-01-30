// leetcode url - https://leetcode.com/problems/permutations/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    vector<vector<int>> ans;
    void recur1(vector<int>&nums ,vector<int>& current,int &n){
        if(n==current.size()) ans.push_back(current);
        else{
            for(int i=0;i<n;i++){
                if(nums[i]==-11) continue;
                current.push_back(nums[i]);
                int temp=nums[i];
                nums[i]=-11;
                recur1(nums,current,n);
                nums[i]=temp;
                current.pop_back();

            }
        }
    }
    void recur2(vector<int>& nums,int swapIdx,int &n){
        if(swapIdx==n) ans.push_back(nums);
        else{
            for(int i=swapIdx;i<n;i++){
                swap(nums[swapIdx],nums[i]);
                recur2(nums,swapIdx+1,n);
                swap(nums[swapIdx],nums[i]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;
        int n=nums.size();
        recur1(nums,current,n);
        // recur2(nums,0,n);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.permute(nums);

    for (const auto& permutation : result) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}