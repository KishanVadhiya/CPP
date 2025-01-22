// leetcode url - https://leetcode.com/problems/sqrtx/
#include<iostream>
#include<climits>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int start=0, end=x/2+1;
        int mid;
        int ans=-1;
        while(start<=end){
            mid=start+(end-start)/2;
            if((mid)*long(mid)>(INT_MAX) || mid*mid>x){
                end=mid-1;
                continue;
            }
            else if(mid*mid==x) return mid;
            else{
                ans=mid;
                start=mid+1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int x;
    cout << "Enter a number: ";
    cin >> x;
    int result = sol.mySqrt(x);
    cout << "The square root of " << x << " is " << result << endl;
    return 0;
}