#include<iostream>
#include<vector>
using namespace std;

int fibbMemo(int n,vector<int> &dp){
    if(dp[n]!=-1) return dp[n];

    return dp[n]=fibbMemo(n-1,dp)+ fibbMemo(n-2,dp);
}

int fibbTabulation(int n){
    if(n<=1) return n;
    vector<int> dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }

    return dp[n];
}

int fibbConstantMemory(int n){
    if(n<=1) return n;

    int a=0;
    int b=1;

    for(int i=2;i<=n;i++){
        // a+=b;
        // swap(a,b);
        int sum=a+b;
        a=b;
        b=sum;    
    }

    return b;
}

int main(){
    int n=6;
    vector<int> dp(n+1,-1);
    dp[0]=0;
    dp[1]=1;
    cout<<fibbMemo(n,dp)<<endl;
    cout<<fibbTabulation(n)<<endl;
    cout<<fibbConstantMemory(n)<<endl;

    return 0;
}