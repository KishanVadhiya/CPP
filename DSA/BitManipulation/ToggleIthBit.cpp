#include<iostream>
using namespace std;

int main(){
    int num=13;
    int i=2;
    int bitVal=1<<i;
    int ans=num^bitVal;

    cout<<ans;
}