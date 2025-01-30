// leetcode url - https://leetcode.com/problems/combination-sum/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    vector<vector<int>> ans;
    void recur(vector<int> &candidates,int target,int i,vector<int> &current){
        if(0==target) ans.push_back(current);
            for(;i<candidates.size() && (candidates[i]<=target);i++){
                current.push_back(candidates[i]);
                recur(candidates,target-candidates[i],i,current);
                current.pop_back();
            }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        recur(candidates,target,0,temp);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = sol.combinationSum(candidates, target);

    cout << "Combinations that sum to " << target << " are:" << endl;
    for (const auto& combination : result) {
        cout << "[";
        for (size_t i = 0; i < combination.size(); ++i) {
            cout << combination[i];
            if (i < combination.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}