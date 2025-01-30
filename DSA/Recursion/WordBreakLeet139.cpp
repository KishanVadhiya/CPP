// leetcode url - https://leetcode.com/problems/word-break/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
    vector<int> memoization;
    bool backtrack(string&s,vector<string>& wordDict,int i,int n){
        if(i==n) return true;
        if(memoization[i]==1) return false;
        for(string word:wordDict){
            int m=word.length();
            if(i+m>n) continue;
            // cout<<"i: "<<i<<" i+m: "<<i+m<<endl;
            // cout<<"checking dict word : "<<word<<" Against substr: "<<s.substr(i,i+m)<<endl;
            if(word==s.substr(i,m)){
                // cout<<"Word : "<<word<<endl;
                if(backtrack(s,wordDict,i+m,n)) return true;
            }
        }
        memoization[i]=1;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        memoization=vector<int>(n);
        return backtrack(s,wordDict,0,n);
    }
};


int main() {
    Solution solution;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    bool result = solution.wordBreak(s, wordDict);
    cout << (result ? "True" : "False") << endl;
    return 0;
}