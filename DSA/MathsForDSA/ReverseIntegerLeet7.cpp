// leetcode url - https://leetcode.com/problems/reverse-integer/description/

#include<iostream>
#include<climits>
using namespace std;

class Solution {
    public:
        int reverse(int x) {
            int ans=0;
            while(x!=0){
                int digit=x%10;
                x/=10;
                if(ans>INT_MAX/10 || ans<INT_MIN/10) return 0;
                
                ans=ans*10+digit;
            }
            return ans;
        }
    };


    int main() {
        Solution sol;
        int num;
        cout << "Enter an integer: ";
        cin >> num;
        int reversedNum = sol.reverse(num);
        cout << "Reversed integer: " << reversedNum << endl;
        return 0;
    }