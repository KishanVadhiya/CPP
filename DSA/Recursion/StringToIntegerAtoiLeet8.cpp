// leetcode url - https://leetcode.com/problems/string-to-integer-atoi/
#include<iostream>
#include<string>
#include<climits>
using namespace std;
class Solution {
    long recur(string &s,long mul,int n){
        if(n==0) return 0;
        if(mul>=INT_MAX)    return INT_MAX;
        if(mul<=INT_MIN) return INT_MIN;
        long a=long(mul*(s[n-1]-'0'));
        if(a >=INT_MAX) return INT_MAX;
        if(a<=INT_MIN) return INT_MIN;
        long b=recur(s,mul*10,n-1);
        if(b>=INT_MAX) return INT_MAX;
        if(b<=INT_MIN) return INT_MIN;
        long sum=a + b;
        if(sum>=INT_MAX) return INT_MAX;
        if(sum<=INT_MIN) return INT_MIN;
        return sum;

    }
public:
    int myAtoi(string s) {
        bool negative=false;
        int i=0;
        int n=s.length();
        while(i<n && s[i]==' ') i++;
        if(i!=n && s[i]=='-') negative=true;
        if(i!=n && (s[i]=='-' || s[i]=='+')) i++;
        while(i<n&& s[i]=='0') i++;
        int startIdx=i;
        while(i<n && (s[i]>='0' && s[i]<='9')) i++;
        int totalChar=i-startIdx;
        s=s.substr(startIdx,totalChar);
        cout<<s<<endl;
        int mul=(negative)?-1:1;
        int ans= recur(s,mul,s.length());
        return ans;

    }
};

int main() {
    Solution solution;
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    int result = solution.myAtoi(str);
    cout << "Converted integer: " << result << endl;
    return 0;
}