// leetcode url - https://leetcode.com/problems/palindrome-partitioning-ii/

#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;
class Solution {
    bool isPalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    int recur(int i,int n,string &s,vector<int> &dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int mini=INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int cuts=1+recur(j+1,n,s,dp);
                mini=min(mini,cuts);
            }
        }

        return dp[i]=mini;
    }

    int memoization(string &s){
        int n=s.length();
        vector<int> dp(n,-1);
        return recur(0,n,s,dp)-1;
    }

    int tabulation(string &s){
        int n=s.length();
        vector<int> dp(n+1,n-1);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int mini=INT_MAX;
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s)){
                    int cuts=1+dp[j+1];
                    mini=min(mini,cuts);
                }
            }
            dp[i]=mini;
        }
        return dp[0]-1;
    }

    int optimalTabulation(string &s){
        int n=s.length();
        vector<vector<int>> isPal(n,vector<int>(n,1));

        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                isPal[i][j]=(s[i]==s[j] && isPal[i+1][j-1]);
            }
        }

        vector<int> dp(n+1,n-1);
        dp[n]=0;

        for(int i=n-1;i>=0;i--){
            int mini=INT_MAX;
            for(int j=i;j<n;j++){
                if(isPal[i][j]){
                    int cuts=1+dp[j+1];
                    mini=min(mini,cuts);
                } 
            }
            dp[i]=mini;
        }
        return dp[0]-1;
    }
public:
    int minCut(string s) {
        // return memoization(s);
        // return tabulation(s);
        return optimalTabulation(s);
    }
};


int main() {
    Solution solution;
    string s = "aab";
    cout << "Minimum cuts needed for Palindrome Partitioning: " << solution.minCut(s) << endl;
    return 0;
}