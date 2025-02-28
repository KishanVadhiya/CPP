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
        double x = 3;
        int n1 = 10;
        int n2 = -10;

        double result1 = sol.myPow(x, n1);
        cout << x << " raised to the power " << n1 << " is " << result1 << endl;

        double result2 = sol.myPow(x, n2);
        cout << x << " raised to the power " << n2 << " is " << result2 << endl;

        return 0;
    }
