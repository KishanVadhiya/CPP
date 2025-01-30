// leetcode url - https://leetcode.com/problems/generate-parentheses/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
    vector<string> ans;
    void recur(string s,int open,int close){
        if(close==0) ans.push_back(s);
        if(open>0){
            recur(s+"(",open-1,close);
        }
        if(close>open){
            recur(s+")",open,close-1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        recur("(",n-1,n);
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 3; // Example input
    vector<string> result = sol.generateParenthesis(n);
    for(const string& s : result) {
        cout << s << endl;
    }
    return 0;
}