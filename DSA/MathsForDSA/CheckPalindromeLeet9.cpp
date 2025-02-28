// leetcode url - https://leetcode.com/problems/palindrome-number/
#include<iostream>
using namespace std;
class Solution {
    public:
        bool isPalindrome(int x) {
            if(x<0 || (x!=0 && x%10==0)) return false;
    
            int res=0;
            while(res<x){
                res=res*10 + x%10;
                x/=10;
            }
    
            if(x==res || x==res/10){
                return true;
            }
    
            return false;
        }
    };


    int main() {
        Solution solution;
        int input = 154323451;
        if (solution.isPalindrome(input)) {
            cout << input << " is a palindrome." << endl;
        } else {
            cout << input << " is not a palindrome." << endl;
        }
        return 0;
    }