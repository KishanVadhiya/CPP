// leetcode url - https://leetcode.com/problems/climbing-stairs/

#include<iostream>
using namespace std;
class Solution {
    public:
        int climbStairs(int n) {
            if(n<=1) return n;
            
            int a=1;
            int b=1;
    
            for(int i=2;i<=n;i++){
                int sum=a+b;
                a=b;
                b=sum;
            }
    
            return b;
        }
    };

    int main() {
        Solution solution;
        int n;
        cout << "Enter the number of stairs: ";
        cin >> n;
        int result = solution.climbStairs(n);
        cout << "Number of ways to climb " << n << " stairs is: " << result << endl;
        return 0;
    }