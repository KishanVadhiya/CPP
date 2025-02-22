// leetcode url - https://leetcode.com/problems/distinct-subsequences/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
    int recur(int i,int j,string &s,string &t,vector<vector<int>>& dp){
        if(j==0) return dp[i][j]=1;
        if(i==0) return dp[i][j]=0;
        int matched=0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==t[j-1]){
            matched=recur(i-1,j-1,s,t,dp);
        }

        int notmatched= recur(i-1,j,s,t,dp);

        return dp[i][j]=matched+notmatched;
    }
    int memoization(string &s,string &t){
        int n1=s.length();
        int n2=t.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return recur(n1,n2,s,t,dp);
    }

    int tabulation(string &s,string &t){
        int n1=s.length();
        int n2=t.length();
        vector<vector<unsigned int>> dp(n1+1,vector<unsigned int>(n2+1));
        for(int i=0;i<=n1;i++) dp[i][0]=1;

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                int matched=0;
                if(s[i-1]==t[j-1]){
                    matched=dp[i-1][j-1];
                }
                int notmatched=dp[i-1][j];

                dp[i][j]=(unsigned int)(matched)+notmatched;
            }
        }

        return dp[n1][n2];
    }

    int memoryOpti(string &s,string &t){
        int n1=s.length();
        int n2=t.length();
        vector<int> dp(n2+1);
        dp[0]=1;

        for(int i=1;i<=n1;i++){
            int prev=1;
            for(int j=1;j<=n2;j++){
                int temp=dp[j];
                int matched=0;
                if(s[i-1]==t[j-1]) matched=prev;
                int notmatched=dp[j];
                dp[j]=(unsigned int)(matched) + notmatched;
                prev=temp;
            }
        }

        return dp[n2];
    }
public:
    int numDistinct(string s, string t) {
        // return memoization(s,t);
        // return tabulation(s,t);
        return memoryOpti(s,t);
    }
};

int main() {
    Solution sol;
    string s = "rabbbit";
    string t = "rabbit";
    cout << "Number of distinct subsequences: " << sol.numDistinct(s, t) << endl;
    return 0;
}