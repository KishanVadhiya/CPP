#include<iostream>
using namespace std;

int fib(int n){
    if(n<=1) return n;
    int num=fib(n-1)+fib(n-2);
    return num;
}


int main(){
    cout<<"fib(6) : "<<fib(6)<<endl;
    cout<<"fib(10) : "<<fib(10)<<endl;
}