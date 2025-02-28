// leetcode url - https://leetcode.com/problems/count-primes/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    vector<int> prime;
public:
    void sieveOfEratosthenes(int n){
        prime.resize(n+1,1);
        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                for(int j=i*i;j<=n;j+=i){
                    prime[j]=0;
                }
            }
        }
        
    }
    int countPrimes(int n) {
        n--;
        if(n<2) return 0;
        int ans=0;
        sieveOfEratosthenes(n);

        for(int i=2;i<=n;i++) ans+=prime[i];
        return ans;
    }
};


int main() {
    Solution sol;
    int n = 500;
    int result = sol.countPrimes(n);
    cout << "Number of primes less than " << n << " is: " << result << endl;
    return 0;
}
