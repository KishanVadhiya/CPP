// leetcode url - https://leetcode.com/problems/divide-two-integers/
#include<iostream>
#include<climits>
using namespace std;
class Solution {
    public:
        int divide(int dividend, int divisor) {
            if(dividend==divisor) return 1;
            int sign=true;
            if(dividend<0 && divisor>0) sign=false;
            if(dividend>0 && divisor<0) sign=false;
            long n=labs(dividend);
            long d=labs(divisor);
            int cnt;
    
            long ans=0;
            while(n>=d){
                cnt=0;
                while(n>=(d<<(cnt+1))){
                    cnt++;
                }
                ans+=1<<cnt;
                
                n-=(d<<(cnt));
    
            }
    
            
            if(ans==(1<<31)){
                if(sign) return INT_MAX;
                else INT_MIN;
            }
            return (sign)?ans:-ans;
        }
    };


    int main() {
        Solution solution;
        int dividend = 10;
        int divisor = 3;
        cout << "Result of " << dividend << " / " << divisor << " = " << solution.divide(dividend, divisor) << endl;

        dividend = 7;
        divisor = -3;
        cout << "Result of " << dividend << " / " << divisor << " = " << solution.divide(dividend, divisor) << endl;

        dividend = INT_MIN;
        divisor = 1;
        cout << "Result of " << dividend << " / " << divisor << " = " << solution.divide(dividend, divisor) << endl;

        return 0;
    }