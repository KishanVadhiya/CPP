// gfg url - https://www.geeksforgeeks.org/problems/shortest-job-first/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-job-first
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
      long long solve(vector<int>& bt) {
          // code here
          sort(bt.begin(),bt.end());
          int totalWait=0;
          int n=bt.size();
          int currentTime=0;
          for(int i=0;i<n;i++){
              totalWait+=currentTime;
              currentTime+=bt[i];
          }
          
          return totalWait/n;
      }
  };


int main() {
    Solution sol;
    vector<int> burstTimes = {6, 8, 7, 3};
    cout << "Average waiting time: " << sol.solve(burstTimes) << endl;
    return 0;
}