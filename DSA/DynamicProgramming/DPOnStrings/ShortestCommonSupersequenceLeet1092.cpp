// leetcode url - https://leetcode.com/problems/shortest-common-supersequence/
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
class Solution {
    string tabulation(string &text1,string &text2){
        int n1=text1.length();
        int n2=text2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i1=1;i1<=n1;i1++){
            for(int i2=1;i2<=n2;i2++){
                if(text1[i1-1]==text2[i2-1]) dp[i1][i2]=1+dp[i1-1][i2-1];
                else dp[i1][i2]=max(dp[i1-1][i2],dp[i1][i2-1]);
            }
        }
        string ans="";
        int i=n1;
        int j=n2;
        while(i>0 && j>0){
            if(text1[i-1]==text2[j-1]){
                ans.push_back(text1[i-1]);
                i--;
                j--;
            }else{
                if(dp[i-1][j]>=dp[i][j-1]){
                    ans.push_back(text1[--i]);
                    // i--;
                }else{
                    ans.push_back(text2[--j]);
                    // j--;
                }
            }
        }

        while(i!=0) ans.push_back(text1[--i]);
        while(j!=0) ans.push_back(text2[--j]);
        reverse(begin(ans),end(ans));
        return ans;
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        return tabulation(str1,str2);
    }
};

int main() {
    Solution sol;
    string str1 = "abac";
    string str2 = "cab";
    string result = sol.shortestCommonSupersequence(str1, str2);
    cout << "The shortest common supersequence is: " << result << endl;
    return 0;
}