// leetcode url - https://leetcode.com/problems/longest-increasing-subsequence/
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
class Solution {
    int recur(int currIdx,int prevIdx,int n,vector<int>& arr,vector<vector<int>> &dp){
        if(dp[currIdx][prevIdx]!=-1) return dp[currIdx][prevIdx];
        if(currIdx==n){
            if(arr[currIdx]>arr[prevIdx]) return dp[currIdx][prevIdx]= 1;
            else return dp[currIdx][prevIdx]=0;
        }
        // cout<<"Reached here with : "<<currIdx<<" "<<prevIdx<<endl;
        if(arr[currIdx]>arr[prevIdx]){
            // cout<<"Reached here: "<<endl;
            return dp[currIdx][prevIdx]=max(1+recur(currIdx+1,currIdx,n,arr,dp),recur(currIdx+1,prevIdx,n,arr,dp));
        }else{
            return dp[currIdx][prevIdx]=recur(currIdx+1,prevIdx,n,arr,dp);
        }
    }

    int memoization(vector<int>& arr){
        int n=arr.size();
        arr.insert(arr.begin(),INT_MIN);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return recur(1,0,n,arr,dp);
    }

    int tabulation(vector<int>& arr){
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        arr.insert(arr.begin(),INT_MIN);
        for(int prevIdx=0;prevIdx<=n;prevIdx++){
            if(arr[n]>arr[prevIdx]) dp[n][prevIdx]=1;
            else dp[n][prevIdx]=0;
        }

        for(int currIdx=n-1;currIdx>=1;currIdx--){
            for(int prevIdx=n-1;prevIdx>=0;prevIdx--){
                if(arr[currIdx]>arr[prevIdx]){
                    dp[currIdx][prevIdx]=max(1+dp[currIdx+1][currIdx],dp[currIdx+1][prevIdx]);
                }else{
                    dp[currIdx][prevIdx]=dp[currIdx+1][prevIdx];
                }
            }
        }

        return dp[1][0];
    }

    int memoryOpti(vector<int>& arr){
        int n=arr.size();
        vector<int> dp(n+1),temp(n+1);
        arr.insert(arr.begin(),INT_MIN);
        for(int prevIdx=0;prevIdx<=n;prevIdx++){
            if(arr[n]>arr[prevIdx]) dp[prevIdx]=1;
            else dp[prevIdx]=0;
        }

        for(int currIdx=n-1;currIdx>=0;currIdx--){
            for(int prevIdx=n-1;prevIdx>=0;prevIdx--){
                if(arr[currIdx]>arr[prevIdx]){
                    temp[prevIdx]=max(1+dp[currIdx],dp[prevIdx]);
                }else{
                    temp[prevIdx]=dp[prevIdx];
                }
            }
            dp=temp;
        }

        return dp[0];
    }

    int memoryOpti2(vector<int>& arr){
        int n=arr.size();
        vector<int> dp(n,1);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j] && dp[i]<=dp[j]){
                    dp[i]=dp[j]+1;
                }
            }
        }

        return *max_element(dp.begin(),dp.end());
    }

    int optimalGreedyBinary(vector<int>& arr){
        vector<int> temp;
        temp.push_back(arr[0]);
        int n=arr.size();
        for(int i=1;i<n;i++){
            if(arr[i]>temp.back()) temp.push_back(arr[i]);
            else{
                int idx=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
                temp[idx]=arr[i];
            }
        }
        return temp.size();
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        // return memoization(nums);
        // return tabulation(nums);
        // return memoryOpti(nums);
        // return memoryOpti2(nums);
        return optimalGreedyBinary(nums);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " << sol.lengthOfLIS(nums) << endl;
    return 0;
}