
#include<iostream>
#include<vector>
using namespace std;
#define ll long long int

ll recur(int i,int j,int isTrue,string& s,vector<vector<vector<int>>> &dp){

    if(i==j){
        if(isTrue) return s[i]=='T';
        else return s[i]=='F';
    }
    if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
    ll sum=0;
    for(int k=i+1;k<j;k+=2){
        ll leftTrue=recur(i,k-1,true,s,dp);
        ll leftFalse=recur(i,k-1,false,s,dp);
        ll rightTrue=recur(k+1,j,true,s,dp);
        ll rightFalse=recur(k+1,j,false,s,dp);
        ll ways=0;
        if(s[k]=='&'){
            if(isTrue){
                ways=leftTrue*rightTrue;
            }else{
            
            ways=leftTrue*rightFalse + leftFalse*rightTrue + leftFalse*rightFalse;
            }
        }else if(s[k]=='|'){
            if(isTrue){
                ways=leftTrue*rightFalse + leftFalse*rightTrue + leftTrue*rightTrue;
            }else{
                ways=leftFalse*rightFalse;
            }
        }else{
            if(isTrue){
                ways=leftTrue*rightFalse + leftFalse*rightTrue;
            }else{
                ways=leftTrue*rightTrue+leftFalse*rightFalse;
            }
        }
        sum+=ways%1000000007;

    }
    return dp[i][j][isTrue]=sum%1000000007;


}

int memoization(string &s){
    int n=s.length();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
    return recur(0,n-1,true,s,dp);
}

int tabulation(string &s){
    int n=s.length();
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(n,vector<ll>(2,-1)));
    for(int i=0;i<n;i++){
        dp[i][i][1]=(s[i]=='T');
        dp[i][i][0]=(s[i]=='F');
    }
    for(int i=n-1;i>=0;i-=2){
        for(int j=i+2;j<n;j+=2){
            for(int isTrue=0;isTrue<2;isTrue++){
            ll sum=0;
            for(int k=i+1;k<j;k+=2){
                ll leftTrue=dp[i][k-1][1];
                ll leftFalse=dp[i][k-1][0];
                ll rightTrue=dp[k+1][j][1];
                ll rightFalse=dp[k+1][j][0];
                ll ways=0;
                if(s[k]=='&'){
                    if(isTrue){
                        ways=leftTrue*rightTrue;
                    }else{
                    
                    ways=leftTrue*rightFalse + leftFalse*rightTrue + leftFalse*rightFalse;
                    }
                }else if(s[k]=='|'){
                    if(isTrue){
                        ways=leftTrue*rightFalse + leftFalse*rightTrue + leftTrue*rightTrue;
                    }else{
                        ways=leftFalse*rightFalse;
                    }
                }else{
                    if(isTrue){
                        ways=leftTrue*rightFalse + leftFalse*rightTrue;
                    }else{
                        ways=leftTrue*rightTrue+leftFalse*rightFalse;
                    }
                }
                sum+=ways%1000000007;

            }

            dp[i][j][isTrue]=sum%1000000007;
            }
        }
    }

    return dp[0][n-1][true];
}

int evaluateExp(string & exp) {
    // Write your code here.
    // return memoization(exp);
    return tabulation(exp);
}


int main() {
    string expression = "T|F&T^T";
    cout << "Number of ways to evaluate the expression to true: " << evaluateExp(expression) << endl;
    return 0;
}