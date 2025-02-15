// leetcode url - https://leetcode.com/problems/lemonade-change/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        bool lemonadeChange(vector<int>& bills) {
            int fiveD=0;
            int tenD=0;
            int n=bills.size();
            for(int i=0;i<n;i++){
                if(bills[i]==5) fiveD++;
                else if(bills[i]==10){
                    if(fiveD==0) return false;
                    fiveD--;
                    tenD++;
                }else{
                    if(tenD>0 && fiveD>0){
                        tenD--;
                        fiveD--;
                    }else if(fiveD>=3){
                        fiveD-=3;
                    }else{
                        return false;
                    }
                }
            }
    
            return true;
        }
    };


    int main() {
        Solution solution;
        vector<int> bills1 = {5, 5, 5, 10, 20};
        vector<int> bills2 = {5, 5, 10, 10, 20};
        
        cout << "Test case 1: " << (solution.lemonadeChange(bills1) ? "True" : "False") << endl;
        cout << "Test case 2: " << (solution.lemonadeChange(bills2) ? "True" : "False") << endl;
        
        return 0;
    }