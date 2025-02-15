// leetcode url - https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
#include<iostream>
#include<string>
using namespace std;
class Solution {
    public:
        int numberOfSubstrings(string s) {
            int start=0;
            int end=0;
            int ans=0;
            int n=s.length();
            int a=0,b=0,c=0;
    
            while(end<n){
                if(a==0 || b==0 || c==0){
                    if(s[end]=='a') a++;
                    else if(s[end]=='b') b++;
                    else c++;
                }
                if(a>0 && b>0 && c>0){
                    int subArrayCnt=n-end;
                    int initialStart=start;
                    while(a>0 && b>0 && c>0){
                        if(s[start]=='a') a--;
                        else if(s[start]=='b') b--;
                        else c--;
                        start++;
                    }
                    ans+=(start-initialStart)*subArrayCnt;
    
                }
                end++;
            }
    
            return ans;
        }
    };


    int main() {
        Solution solution;
        string s = "abcabc";
        int result = solution.numberOfSubstrings(s);
        cout << "Number of substrings containing all three characters: " << result << endl;
        return 0;
    }