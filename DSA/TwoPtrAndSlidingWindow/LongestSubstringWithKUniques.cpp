// gfg url - https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
    public:
      int longestKSubstr(string &s, int k) {
          // your code here
          int ans=-1;
          int start=0;
          int end=0;
          int n=s.length();
          vector<int> cnt(26);
          while(end<n){
              int idx=s[end]-'a';
              if(cnt[idx]>0){
                  cnt[idx]++;
                  end++;
              }else{
                  if(k>0){
                      cnt[idx]++;
                      end++;
                      k--;
                  }else{
                      while(k==0){
                          int tempIdx=s[start]-'a';
                          cnt[tempIdx]--;
                          if(cnt[tempIdx]==0) k++;
                          start++;
                      }
                  }
              }
  
              if(k==0)    ans=max(ans,end-start);
          }
          
          return ans;
      }
  };



int main() {
    string s = "aabacbebebe";
    int k = 3;
    Solution sol;
    int result = sol.longestKSubstr(s, k);
    cout << "The length of the longest substring with " << k << " unique characters is: " << result << endl;
    return 0;
}