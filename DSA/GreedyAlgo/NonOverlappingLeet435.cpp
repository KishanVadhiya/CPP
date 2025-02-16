// leetcode url - https://leetcode.com/problems/non-overlapping-intervals/
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
class Solution {
    public:
        static bool comp(vector<int> &a,vector<int> &b){
            return a[1]<b[1];
        }
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            // int nonOverlap=0;
            sort(intervals.begin(),intervals.end(),comp);
            int n=intervals.size();
            int lastMeetingEnd=INT_MIN;
            int ans=0;
            for(int i=0;i<n;i++){
                if(intervals[i][0]>=lastMeetingEnd){
                    // nonOverlap++;
                    lastMeetingEnd=intervals[i][1];
                }else{
                    ans++;
                }
            }
            // cout<<ans<<endl;
            return ans;
        }
    };


    int main() {
        Solution sol;
        vector<vector<int>> intervals = {{1,2}, {2,3}, {3,4}, {1,3}};
        int result = sol.eraseOverlapIntervals(intervals);
        cout << "Number of intervals to remove: " << result << endl;
        return 0;
    }