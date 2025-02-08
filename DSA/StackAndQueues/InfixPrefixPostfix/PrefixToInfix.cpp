
#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
    string comb(string &a,string &b,char operat){
        return "("+a+string(1,operat)+b+")";
    }
  public:
    string preToInfix(string s) {
        // Write your code here
        int n=s.length();
        stack<string> st;
        for(int i=n-1;i>=0;i--){
            if(isalnum(s[i])) st.push(string(1,s[i]));
            else{
                string a=st.top();st.pop();
                string b=st.top();st.pop();
                st.push(comb(a,b,s[i]));
            }
        }
        return st.top();
    }
};

int main() {
    Solution sol;
    string prefix = "*-A/BC-/AKL";
    cout << "Infix expression: " << sol.preToInfix(prefix) << endl;
    return 0;
}