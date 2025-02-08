
#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
    string comb(string a,string b,char operat){
        a="("+a;
        a.push_back(operat);
        b.push_back(')');
        return a+b;
    }
  public:
    string postToInfix(string s) {
        // Write your code here
        stack<string> st;
        int n=s.length();
        for(int i=0;i<n;i++){
            // stack<string> cp=st;
            // while(!cp.empty()){
            //     cout<<cp.top()<<" ";
            //     cp.pop();
            // }
            // cout<<endl;
            if(isalnum(s[i])) st.push(string(1,s[i]));
            else{
                string b=st.top();st.pop();
                string a=st.top();st.pop();
                st.push(comb(a,b,s[i]));
        }
        }
        return st.top();
    }
};


int main() {
    Solution sol;
    string postfix = "ab+c*";
    cout << "Infix expression: " << sol.postToInfix(postfix) << endl;
    return 0;
}