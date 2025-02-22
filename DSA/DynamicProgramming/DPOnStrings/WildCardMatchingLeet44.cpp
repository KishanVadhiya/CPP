// leetcode url - https://leetcode.com/problems/wildcard-matching/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
    bool recur(int i,int j,string &s,string &p,vector<vector<int>>& dp){
        if(i==0 && j!=0) return dp[i][j]=(p[j-1]=='*')?recur(i,j-1,s,p,dp):false;
        if(i==0 && j==0) return dp[i][j]=true;
        if(i==0 || j==0) return dp[i][j]=false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(p[j-1]=='*') {
            return dp[i][j]=recur(i,j-1,s,p,dp) || recur(i-1,j,s,p,dp);
        }else{
            if(p[j-1]==s[i-1] || p[j-1]=='?') return dp[i][j]=recur(i-1,j-1,s,p,dp);
            else return dp[i][j]=false;
        }
    }

    bool memoization(string &s,string &p){
        int n1=s.length();
        int n2=p.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return recur(n1,n2,s,p,dp);
    }

    bool tabulation(string &s,string &p){
        int n1=s.length();
        int n2=p.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1));
        int j=1;
        dp[0][0]=true;
        while(p[j-1]=='*') dp[0][j++]=true;

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(p[j-1]=='*') dp[i][j]=dp[i-1][j] || dp[i][j-1];
                else{
                    if(p[j-1]==s[i-1] || p[j-1]=='?') dp[i][j]=dp[i-1][j-1];
                    else dp[i][j]=false;
                }
            }
        }

        return dp[n1][n2];

    }

    bool memoryOpt(string &s,string &p){
        int n1=s.length();
        int n2=p.length();
        vector<int> dp(n2+1);
        dp[0]=true;
        int j=1;
        while(p[j-1]=='*') dp[j++]=true;

        for(int i=1;i<=n1;i++){
            vector<int> temp(n2+1);
            for(int j=1;j<=n2;j++){
                if(p[j-1]=='*') temp[j]=dp[j] || temp[j-1];
                else{
                    if(p[j-1]==s[i-1] || p[j-1]=='?') temp[j]=dp[j-1];
                    else temp[j]=false;
                }
            }
            dp=temp;
        }

        return dp[n2];
    }
public:
    bool isMatch(string s, string p) {
        // return memoization(s,p);
        // return tabulation(s,p);
        return memoryOpt(s,p);
    }
};


int main() {
    Solution solution;
    string s = "adceb";
    string p = "*a*b";
    if (solution.isMatch(s, p)) {
        cout << "The string matches the pattern." << endl;
    } else {
        cout << "The string does not match the pattern." << endl;
    }
    return 0;
}