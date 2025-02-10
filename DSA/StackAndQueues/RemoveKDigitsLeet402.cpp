// leetcode url - https://leetcode.com/problems/remove-k-digits/
#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
    public:
        string removeKdigits(string num, int k) {
            string st;
            int n=num.length();
            if(n==k) return "0";
            int i=0;
            for(;i<n && k>0;i++){
                if(st.length()==0 && num[i]=='0') continue;
    
                while(st.length()>0 && k>0 && num[i]<st.back()){
                    st.pop_back();
                    k--;
                }
                if(st.length()==0 && num[i]=='0') continue;
                st.push_back(num[i]);
            }
            // cout<<"Reached here 1 : "<<endl;
            for(;i<n;i++){
                if(st.length()==0 && num[i]=='0') continue;
                st.push_back(num[i]);
            }
    
            // cout<<"Reached here 2 : "<<endl;
    
            for(;k>0 && st.length()>0;k--){
    
                st.pop_back();
            }
    
            // cout<<"Reached here 3: "<<endl;
    
            return (st.length()==0)?"0":st;
        }
    };


    int main() {
        Solution sol;
        string num = "1432219";
        int k = 3;
        cout << "Result after removing " << k << " digits: " << sol.removeKdigits(num, k) << endl;
        return 0;
    }