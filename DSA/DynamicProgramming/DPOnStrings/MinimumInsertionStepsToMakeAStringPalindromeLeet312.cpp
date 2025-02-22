// leetcode url - https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
    int memoryOpti2(string &s1){
        int n=s1.length();
        
        vector<int> dp(n+1);

        for(int i=n;i>0;i--){
            int prev=0;
            for(int j=1;j<=n;j++){
                int temp=dp[j];
                if(s1[i-1]==s1[j-1]){
                    dp[j]=1+prev;
                }else{
                    dp[j]=max(dp[j],dp[j-1]);
                }
                prev=temp;
            }
        }

        return n-dp[n];
    }
public:
    int minInsertions(string s) {
        return memoryOpti2(s);
    }
};

int main() {
    Solution sol;
    string s = "abcaa";
    int result = sol.minInsertions(s);
    cout << "Minimum insertions to make the string a palindrome: " << result << endl;
    return 0;
}