// leetcode url - https://leetcode.com/problems/combination-sum-ii/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    vector<vector<int>> ans;
    void recur(vector<int> &candidates,int target,int start,vector<int> &current){
        if(0==target) ans.push_back(current);
            for(int i=start;i<candidates.size() && (candidates[i]<=target);i++){
                if(i>start && candidates[i]==candidates[i-1]) continue;
                current.push_back(candidates[i]);
                recur(candidates,target-candidates[i],i+1,current);
                current.pop_back();
            }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        recur(candidates,target,0,temp);
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> result = sol.combinationSum2(candidates, target);

    cout << "Combinations that sum to " << target << " are:" << endl;
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}