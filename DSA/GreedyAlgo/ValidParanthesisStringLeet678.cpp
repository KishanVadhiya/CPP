// leetcode url - https://leetcode.com/problems/valid-parenthesis-string/submissions/1544993065/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
    vector<vector<int>> dp;

    bool backtrack(string &s, int i, int n, int cnt) {
        if (i == n) return (cnt == 0) ? true : false;
        if (cnt < 0) return false;
        if (dp[i][cnt] > -1) return dp[i][cnt];
        if (s[i] == '(') return dp[i][cnt] = backtrack(s, i + 1, n, cnt + 1);
        if (s[i] == ')') return dp[i][cnt] = backtrack(s, i + 1, n, cnt - 1);
        return dp[i][cnt] = (backtrack(s, i + 1, n, cnt + 1) || backtrack(s, i + 1, n, cnt - 1) || backtrack(s, i + 1, n, cnt));
    }

public:
    bool checkValidStringStack(string s) {
        stack<int> openBrackets;
        stack<int> astericks;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '(') {
                openBrackets.push(i);
            } else if (ch == '*') {
                astericks.push(i);
            } else {
                if (!openBrackets.empty()) {
                    openBrackets.pop();
                } else if (!astericks.empty()) {
                    astericks.pop();
                } else {
                    return false;
                }
            }
        }

        while (!openBrackets.empty() && !astericks.empty()) {
            if (openBrackets.top() > astericks.top()) {
                return false;
            }
            openBrackets.pop();
            astericks.pop();
        }

        return openBrackets.empty();
    }

    bool checkValidStringDP(string s) {
        int n = s.length();
        dp.resize(n, vector<int>(n, -1));
        return backtrack(s, 0, n, 0);
    }

    bool checkValidStringGreedy2Ptr(string s) {
        int minn = 0;
        int maxx = 0;

        for (auto it : s) {
            if (it == '(') {
                minn++;
                maxx++;
            } else if (it == ')') {
                minn = max(0, minn - 1);
                maxx--;
                if (maxx < 0) return false;
            } else {
                minn = max(0, minn - 1);
                maxx++;
            }
        }

        return minn == 0;
    }

    bool checkValidString(string s) {
        return checkValidStringGreedy2Ptr(s);
        // return checkValidStringStack(s);
        // return checkValidStringDP(s);
    }
};


int main() {
    Solution solution;
    string s;

    cout << "Enter a string containing '(', ')' and '*': ";
    cin >> s;

    if (solution.checkValidString(s)) {
        cout << "The string is a valid parenthesis string." << endl;
    } else {
        cout << "The string is not a valid parenthesis string." << endl;
    }

    return 0;
}