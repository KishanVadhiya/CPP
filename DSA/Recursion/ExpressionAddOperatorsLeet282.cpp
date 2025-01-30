// leetcode url - https://leetcode.com/problems/expression-add-operators/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
    vector<string> ans;

    void recur(string current,string &num,long prevNum,int target,long res,int i,int n){
        if(n==i){
            if(res==target) ans.push_back(current);
            return ;
        }

        for(int j=i;j<n;j++){
            if(num[i]=='0' && j>i){
             break;
            }
            string currentNumStr=num.substr(i,j-i+1);
            long currentNum=stol(currentNumStr);
            if(i==0){
                recur(currentNumStr,num,currentNum,target,currentNum,j+1,n);
                continue;
            }

            recur((current+"+"+currentNumStr),num,currentNum,target,res+currentNum,j+1,n);
            recur((current+"-"+currentNumStr),num,-currentNum,target,res-currentNum,j+1,n);
            recur((current+"*"+currentNumStr),num,prevNum*currentNum,target,res-prevNum+prevNum*currentNum,j+1,n);

        }
    }
public:
    vector<string> addOperators(string num, int target) {
        recur("",num,0,target,0,0,num.length());
        return ans;
    }
};


int main() {
    Solution sol;
    string num = "123";
    int target = 6;
    vector<string> result = sol.addOperators(num, target);

    for (const string &expression : result) {
        cout << expression << endl;
    }

    return 0;
}