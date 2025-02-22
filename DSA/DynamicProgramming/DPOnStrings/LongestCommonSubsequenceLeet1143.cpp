// leetcode url - https://leetcode.com/problems/longest-common-subsequence/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
    int recur(int i1,int i2,string &text1,string &text2,vector<vector<int>>& dp){
        if(i1<0 || i2<0) return 0;
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        if(text1[i1]==text2[i2]) return dp[i1][i2]=1+ recur(i1-1,i2-1,text1,text2,dp);

        return dp[i1][i2]=max(recur(i1-1,i2,text1,text2,dp),recur(i1,i2-1,text1,text2,dp));
    }

    int memoization(string text1,string text2){
        int n1=text1.length();
        int n2=text2.length();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return recur(n1-1,n2-1,text1,text2,dp);
    }

    int tabulation(string &text1,string &text2){
        int n1=text1.length();
        int n2=text2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i1=1;i1<=n1;i1++){
            for(int i2=1;i2<=n2;i2++){
                if(text1[i1-1]==text2[i2-1]) dp[i1][i2]=1+dp[i1-1][i2-1];
                else dp[i1][i2]=max(dp[i1-1][i2],dp[i1][i2-1]);
            }
        }

        return dp[n1][n2];
    }

    int memoryOpti(string &text1,string &text2){
        int n1=text1.length();
        int n2=text2.length();

        vector<int> dp(n2+1);

        for(int i1=1;i1<=n1;i1++){
            vector<int> temp(n2+1);
            for(int i2=1;i2<=n2;i2++){
                if(text1[i1-1]==text2[i2-1]) temp[i2]=1+dp[i2-1];
                else temp[i2]=max(dp[i2],temp[i2-1]);
            }
            dp=temp;
        }

        return dp[n2];
    }

    int memoryOpti2(string &text1,string &text2){
        int n1=text1.length();
        int n2=text2.length();

        vector<int> dp(n2+1);

        for(int i1=1;i1<=n1;i1++){
            // vector<int> temp(n2+1);
            int prev=0;
            for(int i2=1;i2<=n2;i2++){
                int temp=dp[i2];
                if(text1[i1-1]==text2[i2-1]) {
                    dp[i2]=1+prev;
                    }
                else dp[i2]=max(dp[i2],dp[i2-1]);
                prev=temp;
            }
            // dp=temp;
        }

        return dp[n2];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        // return memoization(text1,text2);
        // return tabulation(text1,text2);
        // return memoryOpti(text1,text2);
        return memoryOpti2(text1,text2);
    }
};



int main() {
    Solution sol;
    string text1 = "abcde";
    string text2 = "ace";
    cout << "The length of the longest common subsequence is: " << sol.longestCommonSubsequence(text1, text2) << endl;
    return 0;
}