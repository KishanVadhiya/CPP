// leetcode url - https://leetcode.com/problems/edit-distance/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
    int recur(int i,int j,string &w1,string &w2, vector<vector<int>> &dp){
        if(j==0) return dp[i][j]=i;
        if(i==0) return dp[i][j]=j;
        if(dp[i][j]!=-1) return dp[i][j];
        if(w1[i-1]==w2[j-1]) return dp[i][j]=recur(i-1,j-1,w1,w2,dp);
        else{
            int ins=recur(i,j-1,w1,w2,dp);
            int del=recur(i-1,j,w1,w2,dp);
            int rep=recur(i-1,j-1,w1,w2,dp);
            return dp[i][j]=1+min(ins,min(del,rep));
        }

    }

    int memoization(string &w1,string &w2){
        int n1=w1.length();
        int n2=w2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return recur(n1,n2,w1,w2,dp);
    }
    int tabulation(string &w1,string &w2){
        int n1=w1.length();
        int n2=w2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1));
        for(int i=0;i<=n1;i++) dp[i][0]=i;
        for(int j=0;j<=n2;j++) dp[0][j]=j;

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(w1[i-1]==w2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    int ins=dp[i][j-1];
                    int del=dp[i-1][j];
                    int rep=dp[i-1][j-1];

                    dp[i][j]=1+min(ins,min(del,rep));
                }
            }
        }

        return dp[n1][n2];
    }

    int memoryOpti(string &w1,string &w2){
        int n1=w1.length();
        int n2=w2.length();
        vector<int> prev(n2+1),curr(n2+1);

        for(int j=0;j<=n2;j++) prev[j]=j;

        for(int i=1;i<=n1;i++){
            curr[0]=i;
            for(int j=1;j<=n2;j++){
                if(w1[i-1]==w2[j-1]){
                    curr[j]=prev[j-1];
                }else{
                    int ins=curr[j-1];
                    int del=prev[j];
                    int rep=prev[j-1];

                    curr[j]=1+min(ins,min(del,rep));
                }
            }
            prev=curr;
        }

        return prev[n2];

    }
public:
    int minDistance(string word1, string word2) {
        if(word1==word2) return 0;
        // return memoization(word1,word2);
        // return tabulation(word1,word2);
        return memoryOpti(word1,word2);
    }
};


int main() {
    Solution sol;
    string word1 = "intention";
    string word2 = "execution";
    cout << "The minimum edit distance between " << word1 << " and " << word2 << " is: " << sol.minDistance(word1, word2) << endl;
    return 0;
}