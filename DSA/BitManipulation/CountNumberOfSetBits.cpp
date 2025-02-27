#include<iostream>
using namespace std;

void approach1(int n){
    int ans=0;
    while(n>0){
        ans+=n&1;
        n>>=1;
    }

    cout<<ans<<endl;
}

void approach2(int n){
    int ans=0;
    while(n>0){
        n=n&(n-1);
        ans++;
    }
    cout<<ans<<endl;
}
int main(){
    int n=13;
    approach1(n);
    approach2(n);
    return 0;
}