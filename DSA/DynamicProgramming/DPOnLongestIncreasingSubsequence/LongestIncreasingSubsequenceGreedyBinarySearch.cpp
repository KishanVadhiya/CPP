// gfg url - https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-increasing-subsequence
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
    int optimalGreedyBinary(vector<int>& arr){
          vector<int> temp;
          temp.push_back(arr[0]);
          int n=arr.size();
          for(int i=1;i<n;i++){
              if(arr[i]>temp.back()) temp.push_back(arr[i]);
              else{
                  int idx=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
                  temp[idx]=arr[i];
              }
          }
          return temp.size();
      }
      // Function to find length of longest increasing subsequence.
      int lis(vector<int>& arr) {
          // code here
          return optimalGreedyBinary(arr);
      }
  };
  

int main() {
    Solution sol;
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " << sol.lis(arr) << endl;
    return 0;
}