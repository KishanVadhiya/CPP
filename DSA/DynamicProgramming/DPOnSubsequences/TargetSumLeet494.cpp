// leetcode url - https://leetcode.com/problems/target-sum/

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
class Solution {
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int target=accumulate(arr.begin(),arr.end(),0);
        int n=arr.size();
        vector<int> dp(target+1);
        dp[0]=1;
        if(target>=arr[0]) dp[arr[0]]++;
        
        for(int i=1;i<n;i++){
            vector<int> temp(target+1);
            temp[0]=1;
            for(int j=0;j<=target;j++){
                int notPick=dp[j];
                int pick=0;
                if(j>=arr[i]) pick=dp[j-arr[i]];
                
                temp[j]=pick+notPick;
            }
            dp=temp;
        }
        int ans=0;
        for(int j=0;j<=target/2;j++){
            if(d==abs(j-(target-j))){
                ans+=dp[j];
            }
        }
        return ans;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums,abs(target));
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    int result = sol.findTargetSumWays(nums, target);
    cout << "Number of ways to get target sum: " << result << endl;
    return 0;
}