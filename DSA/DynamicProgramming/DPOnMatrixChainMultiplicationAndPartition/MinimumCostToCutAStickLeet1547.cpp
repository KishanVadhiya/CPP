
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
class Solution {
    int recur(int i,int j,vector<int>& arr,vector<vector<int>> &dp){
        if(j-i==1) return dp[i][j]=0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k=i+1;k<j;k++){
            int currCost=arr[j]-arr[i]+recur(i,k,arr,dp)+recur(k,j,arr,dp);
            mini=min(mini,currCost);
        }

        return dp[i][j]=mini;

    }
    int memoization(vector<int>& arr,int n){
        // int len=arr.size();
        arr.push_back(0);
        arr.push_back(n);
        sort(arr.begin(),arr.end());
        int len=arr.size();
        vector<vector<int>> dp(len,vector<int>(len,-1));
        return recur(0,len-1,arr,dp);
    }

    int tabulation(vector<int>& arr,int n){
        arr.push_back(0);
        arr.push_back(n);
        sort(arr.begin(),arr.end());
        int len=arr.size();
        vector<vector<int>> dp(len,vector<int>(len));

        for(int i=len-2;i>=0;i--){
            for(int j=i+2;j<len;j++){
                int mini=INT_MAX;
                // cout<<"i: "<<i<<" j: "<<j<<endl;
                for(int k=i+1;k<j;k++){
                    int operations=arr[j]-arr[i]+dp[i][k]+dp[k][j];
                    mini=min(mini,operations);
                }
                dp[i][j]=mini;
            }
        }

        return dp[0][len-1];
    }
public:
    int minCost(int n, vector<int>& cuts) {
        // return 0;
        // return memoization(cuts,n);
        return tabulation(cuts,n);
    }
};

int main() {
    Solution sol;
    int n = 7;
    vector<int> cuts = {1, 3, 4, 5};
    cout << "Minimum cost to cut the stick: " << sol.minCost(n, cuts) << endl;
    return 0;
}