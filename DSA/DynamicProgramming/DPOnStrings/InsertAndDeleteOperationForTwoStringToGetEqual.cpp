// leetcode url - https://leetcode.com/problems/delete-operation-for-two-strings/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
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

        return n1+n2-dp[n2]*2;
    }
public:
    int minDistance(string word1, string word2) {
        return memoryOpti2(word1,word2);
    }
};

int main() {
    Solution solution;
    string word1 = "sea";
    string word2 = "eat";
    cout << "The minimum number of steps to make the two strings equal is: " << solution.minDistance(word1, word2) << endl;
    return 0;
}