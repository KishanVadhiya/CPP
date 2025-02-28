#include<iostream>
using namespace std;

bool isPrime(int n){
    if(n<2) return false;
    for(int i=2;i*i<n;i++){
        if(n%i==0) return false;
    }

    return true;
}


int main() {
    int test1 = 5;
    int test2 = 10;
    int test3 = 17;

    cout << "Is " << test1 << " a prime number? " << (isPrime(test1) ? "Yes" : "No") << endl;
    cout << "Is " << test2 << " a prime number? " << (isPrime(test2) ? "Yes" : "No") << endl;
    cout << "Is " << test3 << " a prime number? " << (isPrime(test3) ? "Yes" : "No") << endl;

    return 0;
}