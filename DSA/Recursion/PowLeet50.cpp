// leetcode url - https://leetcode.com/problems/powx-n/

#include<iostream>
using namespace std;
class Solution {
public:
    double recur(double x,int n){
        if(n==0) return 1;
        if(n==1) return x;
            double num=recur(x,n/2);
        if(n%2==0){
            return num*num;
        }else{
            return x*num*num;
        }
    }
    double recurN(double x,int n){
        if(n==0) return 1;
        if(n==-1) return 1/x;

        double num=recurN(x,n/2);
        if(n%2==0){
            return num*num;
        }else{
            return (1/x)*num*num;
        }

    }
    double myPow(double x, int n) {
        if(x==1) return 1;
        if(n<0){
            return recurN(x,n);
        }else{
            return recur(x,n);
        }
    }
};

int main() {
    Solution sol;
    double x;
    int n;

    cout << "Enter the base (x): ";
    cin >> x;
    cout << "Enter the exponent (n): ";
    cin >> n;

    double result = sol.myPow(x, n);
    cout << "Result: " << result << endl;

    return 0;
}