// gfg url - https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
      // Function to find the minimum number of platforms required at the
      // railway station such that no train waits.
      int findPlatform(vector<int>& arr, vector<int>& dep) {
          // Your code here
          sort(arr.begin(),arr.end());
          sort(dep.begin(),dep.end());
          
          int i=0,j=0;
          int n=arr.size();
          int cnt=0;
          int ans=0;
          while(i<n && j<n){
              if(arr[i]<=dep[j]){
                  cnt++;
                  i++;
                  ans=max(ans,cnt);
              }else{
                  cnt--;
                  j++;
              }
          }
          
          return ans;
      }
  };
  

int main() {
    Solution sol;
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    
    int result = sol.findPlatform(arr, dep);
    cout << "Minimum number of platforms required: " << result << endl;
    
    return 0;
}