
#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
  public:
    string postToPre(string s) {
        // Write your code here
        stack<string> st;
        int n=s.length();
        
        for(int i=0;i<n;i++){
            if(isalnum(s[i])) st.push(string(1,s[i]));
            else{
                string b=st.top();st.pop();
                string a=st.top();st.pop();
                st.push(string(1,s[i])+a+b);
            }
        }
        return st.top();
    }
};

int main() {
    Solution sol;
    string postfix = "ABC/-AK/L-*";
    cout << "Postfix Expression: " << postfix << endl;
    string prefix = sol.postToPre(postfix);
    cout << "Prefix Expression: " << prefix << endl;
    return 0;
}