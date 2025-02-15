// leetcode url - https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            vector<int> cnt(128);
            int start=0;
            int n=s.length();
            int ans=0;
            for(int end=0;end<n;end++){
                while(cnt[s[end]]==1){
                    cnt[s[start++]]=0;
                }
                cnt[s[end]]=1;
                ans=max(ans,end-start+1);
            }
    
            return ans;
        }
    };

    int main() {
        Solution solution;
        string s = "abcabcbb";
        int result = solution.lengthOfLongestSubstring(s);
        cout << "The length of the longest substring without repeating characters is: " << result << endl;
        return 0;
    }