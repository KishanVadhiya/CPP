#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int priority(char ch){
        switch(ch){
            case '+':
            case '-':
            return 1;
            case '*':
            case '/':
            return 2;
            case '^':
            return 3;
            case '(':
            return -1;
        }
        return 0;
    }
    string infixToPostfix(string& s) {

        string ans="";
        stack<char> st;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
            }else if(s[i]==')'){

                while(st.top()!='('){
                    ans.push_back(st.top());st.pop();
                }
                 st.pop();
            }else{
                int pr=priority(s[i]);
                if(pr==0) ans.push_back(s[i]);
                else{
                    if(st.empty() || priority(st.top())<pr){
                        st.push(s[i]);
                    }else{
                        if(s[i]=='^'){
                            while(!st.empty() && priority(st.top())>=pr){
                            ans.push_back(st.top());st.pop();
                        }
                        }
                        else{
                        while(!st.empty() && priority(st.top())>pr){
                            ans.push_back(st.top());st.pop();

                            }
                        }
                        st.push(s[i]);
                    }
                }
            }
            
        }
            while(!st.empty()){
                ans.push_back(st.top());st.pop();
            }
        return ans;
    }

    string infixToPrefix(string &s){
        reverse(s.begin(),s.end());
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(') s[i]=')';
            else if(s[i]==')') s[i]='(';
        }
        string ans=infixToPostfix(s);
        reverse(ans.begin(),ans.end());
        return ans;

    }
};


int main() {
    Solution sol;
    string infix = "a^b^(a-b/c)*(a/k-l)";
    cout << "Infix Expression: " << infix << endl;
    string prefix = sol.infixToPrefix(infix);
    cout << "Prefix Expression: " << prefix << endl;
    return 0;
}