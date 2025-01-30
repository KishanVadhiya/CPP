// leetcode url - https://leetcode.com/problems/permutation-sequence/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
    vector<int> factorials;
    void calcFact(int n){
        factorials.push_back(1);
        for(int i=1;i<n;i++){
            factorials.push_back(factorials[i-1]*i);
        }
    }
    string recur(string &ans,string &remaining,int n,int k){
        if(n==0) return ans;
        int idx= (k-1)/factorials[n-1];

        k-=idx*factorials[n-1];
        n--;
        ans.push_back(remaining[idx]);
        remaining.erase(idx,1);
        return recur(ans,remaining,n,k);
    }
public:
    string getPermutation(int n, int k) {
        calcFact(n);
        string ans="";
        string remaining="";
        for(int i=0;i<n;i++){
            remaining.push_back(('1'+i));
        }
        return recur(ans,remaining,n,k);
    }
};


int main() {
    Solution sol;
    int n = 4;
    int k = 9;
    cout << "The " << k << "th permutation sequence of " << n << " numbers is: " << sol.getPermutation(n, k) << endl;
    return 0;
}