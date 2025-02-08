#include<iostream>
#include<stack>
#include<string>
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
        // Your code here
        string ans="";
        stack<char> st;
        int n=s.length();
        for(int i=0;i<n;i++){
            // cout<<"error at idx : "<<i<<endl;
            if(s[i]=='('){
                st.push(s[i]);
            }else if(s[i]==')'){
                // cout<<"Before error"<<endl;
                // cout<<st.empty()<<endl;
                while(st.top()!='('){
                    // cout<<"top is : "<<st.top()<<endl;
                    ans.push_back(st.top());st.pop();
                }
                 st.pop();
            }else{
                int pr=priority(s[i]);
                // cout<<pr<<endl;
                if(pr==0) ans.push_back(s[i]);
                else{
                    // cout<<"Inside else block : "<<endl;
                    if(st.empty() || priority(st.top())<pr){
                        // cout<<"Pushed s[i]"<<s[i]<<endl;
                        st.push(s[i]);
                    }else{
                        // cout<<"Top of stack is : "<<st.top()<<endl;
                        while(!st.empty() && priority(st.top())>=pr){
                            // cout<<"Popping : "<<ans<<endl;
                            ans.push_back(st.top());st.pop();

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
};


int main() {
    Solution sol;
    string infix = "(a-b/c)*(a/k-l)";
    cout << "Infix Expression: " << infix << endl;
    string postfix = sol.infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;
    return 0;
}