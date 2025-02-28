
#include<iostream>
using namespace std;
class Solution {
    public:
      // Function to count the number of digits in n that evenly divide n
      int evenlyDivides(int n) {
          // code here
          int temp=n;
          int ans=0;
          while(temp>0){
              int divisor=temp%10;
              temp/=10;
              // cout<<divisor;
              if(divisor==0) continue;
              // ans+=!(n%divisor);
              if(n%divisor==0) ans++;
          }
          return ans;
      }
  };

int main() {
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int result = sol.evenlyDivides(n);
    cout << "Number of digits in " << n << " that evenly divide " << n << " is: " << result << endl;
    return 0;
}