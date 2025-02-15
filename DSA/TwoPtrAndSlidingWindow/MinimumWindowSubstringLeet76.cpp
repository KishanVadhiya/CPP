// leetcode url  - https://leetcode.com/problems/minimum-window-substring/description/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        string minWindow(string s, string t) {
            vector<int> mp(123);
            int n2=t.length();
            int n1=s.length();
            int cnt=0;
            int startIdx=-1;
            int start=0;
            int lenOfSubstr=1e9;
    
            for(auto it:t){
                mp[it]++;
            }
    
            for(int i=0;i<n1;i++){
                if(mp[s[i]]>0) cnt++;
                mp[s[i]]--;
    
                while(cnt==n2){
                    if(lenOfSubstr>i-start+1){
                        lenOfSubstr=i-start+1;
                        startIdx=start;
                    }
    
                    mp[s[start]]++;
                    if(mp[s[start]]>0) cnt--;
                    start++;
                }
            }
    
            return (startIdx==-1)?"":s.substr(startIdx,lenOfSubstr);
        }
    };


    int main() {
        Solution sol;
        string s = "ADOBECODEBANC";
        string t = "ABC";
        string result = sol.minWindow(s, t);
        cout << "The minimum window substring is: " << result << endl;
        return 0;
    }