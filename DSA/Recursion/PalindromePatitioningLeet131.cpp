// leetcode url - https://leetcode.com/problems/palindrome-partitioning/
#include<iostream>
#include<vector>
#include<string>
using namespace std; 
class Solution {
    vector<vector<string>> ans;

    bool isPalindrome(string&s , int start,int end){
        while(start<end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }

    void recur(vector<string> &current,string &s,int start,int n){
        if(start==n) ans.push_back(current);

        for(int i=start;i<n;i++){
            if(isPalindrome(s,start,i)){
                current.push_back(s.substr(start,i-start+1));
                recur(current,s,i+1,n);
                current.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> current;
        recur(current,s,0,s.length());
        return ans;
    }
};


int main() {
    Solution solution;
    string s = "aab";
    vector<vector<string>> result = solution.partition(s);

    for (const auto& partition : result) {
        for (const auto& str : partition) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}