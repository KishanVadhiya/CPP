// leetcode url -https://leetcode.com/problems/combination-sum-iii/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
    vector<vector<int>> ans;
    void recur(vector<int> &arr,int start,int &sum,int k,int &n){
        if(sum==n && k==0) ans.push_back(arr);
        else if(sum>n || k==0) return ;
        else{
            for(int i=start;i<=9;i++){
                arr.push_back(i);
                sum+=i;
                recur(arr,i+1,sum,k-1,n);
                sum-=i;
                arr.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int a=10-k;
        int Sn=(k*(a+9))/2;
        if(Sn<n) return ans;
        vector<int> temp;
        int sum=0;
        recur(temp,1,sum,k,n);
        return ans;
    }
};

int main() {
    Solution sol;
    int k = 3;
    int n = 7;
    vector<vector<int>> result = sol.combinationSum3(k, n);
    
    for (const auto &comb : result) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}