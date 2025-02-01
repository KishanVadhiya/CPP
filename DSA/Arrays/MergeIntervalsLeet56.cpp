// leetcode url - https://leetcode.com/problems/merge-intervals/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        vector<vector<int>> ans;
        int n=intervals.size();
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            int end= ans.back()[1];
            if(end<intervals[i][0]){
                ans.push_back(intervals[i]);
            }else{
                ans.back()[1]=max(end,intervals[i][1]);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> mergedIntervals = sol.merge(intervals);

    cout << "Merged intervals: ";
    for (const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}