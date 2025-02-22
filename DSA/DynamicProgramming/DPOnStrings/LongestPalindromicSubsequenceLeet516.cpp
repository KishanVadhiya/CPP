// leetcode url - https://leetcode.com/problems/longest-palindromic-subsequence/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
    int tabulation(string &s1,string &s2){
        int n1=s1.length();
        int n2=s2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1));

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[n1][n2];
    }
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

        return dp[n];
    }
public:
    int longestPalindromeSubseq(string s) {
        // string rev=s;
        // reverse(rev.begin(),end(rev));

        return memoryOpti2(s);
    }
};

int main() {
    Solution sol;
    string s = "bbbab";
    cout << "The length of the longest palindromic subsequence is: " << sol.longestPalindromeSubseq(s) << endl;
    return 0;
}