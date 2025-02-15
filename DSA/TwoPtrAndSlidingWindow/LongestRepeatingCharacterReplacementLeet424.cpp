// leet url - https://leetcode.com/problems/longest-repeating-character-replacement/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
    public:
        int characterReplacement(string s, int k) {
            vector<int> cnt(26);
            int start=0;
            // int end=0;
            int n=s.length();
            int ans=0;
            int maxF=0;
            for(int end=0;end<n;end++){
                int idx=s[end]-'A';
                int substrLen=end-start+1;
                cnt[idx]++;
                maxF=max(maxF,cnt[idx]);
    
                if(substrLen-maxF>k){
                    int startIdx=s[start]-'A';
                    cnt[startIdx]--;
                    start++;
                }
    
                if(substrLen-maxF<=k){
                    ans=substrLen;
                }
    
            }
    
            return ans;
        }
    };


    int main() {
        Solution sol;
        string s = "AABABBA";
        int k = 1;
        int result = sol.characterReplacement(s, k);
        cout << "The length of the longest substring after replacement is: " << result << endl;
        return 0;
    }