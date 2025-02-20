// gfg url - https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=partitions-with-given-difference
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
class Solution {
    public:
      int countPartitions(vector<int>& arr, int d) {
          // Code here
          int target=accumulate(arr.begin(),arr.end(),0);
          int n=arr.size();
          vector<int> dp(target+1);
          dp[0]=1;
          if(target>=arr[0]) dp[arr[0]]++;
          
          for(int i=1;i<n;i++){
              vector<int> temp(target+1);
              temp[0]=1;
              for(int j=0;j<=target;j++){
                  int notPick=dp[j];
                  int pick=0;
                  if(j>=arr[i]) pick=dp[j-arr[i]];
                  
                  temp[j]=pick+notPick;
              }
              dp=temp;
          }
          int ans=0;
          for(int j=0;j<=target/2;j++){
              if(d==abs(j-(target-j))){
                  ans+=dp[j];
              }
          }
          return ans;
      }
  };

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    int d = 3;
    int result = sol.countPartitions(arr, d);
    cout << "Number of partitions with given difference: " << result << endl;
    return 0;
}