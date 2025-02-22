
#include<iostream>
#include<string>
#include<vector>
using namespace std;

string tabulation(string &text1,string &text2){
    int n1=text1.length();
    int n2=text2.length();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    for(int i1=1;i1<=n1;i1++){
        for(int i2=1;i2<=n2;i2++){
            if(text1[i1-1]==text2[i2-1]) dp[i1][i2]=1+dp[i1-1][i2-1];
            else dp[i1][i2]=max(dp[i1-1][i2],dp[i1][i2-1]);
        }
    }
    string lcs="";
    for(int i=0;i<dp[n1][n2];i++) lcs+='!';

    // cout<<lcs.length()<<endl;

    for(auto it:dp){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    int i1=n1;
    int i2=n2;
    int idx=dp[n1][n2]-1;
    while(i1>0 && i2>0){
        if(text1[i1-1]==text2[i2-1]){
            lcs[idx--]=text1[i1-1];
            i1--;
            i2--;
        }else{
            if(dp[i1][i2-1]>dp[i1-1][i2]){
                i2--;
            }else{
                i1--;
            }
        }
    }

    return lcs;
}


int main() {
    string text1 = "abcde";
    string text2 = "bdqek";
    string lcs = tabulation(text1, text2);
    cout << "Longest Common Subsequence: " << lcs << endl;
    return 0;
}