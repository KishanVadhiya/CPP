// leetcode url - https://leetcode.com/problems/count-good-numbers/
#include<iostream>
using namespace std;
class Solution {
    const int mod=1e9+7;
    int mul=5;
    long power(long long n){
        if(n==0) return 1;
        if(n==1) return mul;
        long num=power(n/2);
        if(n%2==0){
            return (num*num)%mod;
        }else{
            return (mul*num*num)%mod;
        }
    }

public:
    int countGoodNumbers(long long n) {
        long evenPlaces=power(n/2);
        if(n%2==1){
            evenPlaces=(evenPlaces*5)%mod;
        }
        mul=4;
        long oddPlaces=power(n/2);

        return (evenPlaces*oddPlaces)%mod;
        
    }
};

int main() {
    Solution sol;
    long long n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Count of good numbers: " << sol.countGoodNumbers(n) << endl;
    return 0;
}