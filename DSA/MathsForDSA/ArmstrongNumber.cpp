#include<iostream>
#include<cmath>
using namespace std;
class Solution {
    public:
      bool armstrongNumber(int n) {
          // code here
          int temp=n;
          int res=0;
          while(temp>0){
              res+= pow((temp%10),3);
              temp/=10;
          }
          return res==n;
      }
  };

int main() {
    Solution sol;
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (sol.armstrongNumber(num)) {
        cout << num << " is an Armstrong number." << endl;
    } else {
        cout << num << " is not an Armstrong number." << endl;
    }
    return 0;
}