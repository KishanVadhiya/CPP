// gfg url - https://www.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    int recur(int day,int last,vector<vector<int>>& arr,vector<vector<int>> &dp){
        if(dp[day][last]!=-1) return dp[day][last];
        int maxi=0;
        if(day==0){
            for(int i=0;i<3;i++){
                if(i==last) continue;
                maxi=max(arr[0][i],maxi);
            }
            
            return dp[day][last]=maxi;
        }
        
        
        for(int i=0;i<3;i++){
            if(i==last) continue;
            int curr=arr[day][i]+recur(day-1,i,arr,dp);
            maxi=max(curr,maxi);
        }
        
        return dp[day][last]=maxi;
    }
    int maximumPointsMemo(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(4,-1));
        
        return recur(n-1,3,arr,dp);
    }
    
    int maximumPointsTabulation(vector<vector<int>>& arr){
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(4));
        
        dp[0][0]=max(arr[0][1],arr[0][2]);
        dp[0][1]=max(arr[0][0],arr[0][2]);
        dp[0][2]=max(arr[0][0],arr[0][1]);
        dp[0][3]=max(arr[0][0],max(arr[0][1],arr[0][2]));
        
        for(int day=1;day<n;day++){
            for(int last=0;last<4;last++){
                // dp[day][last]=0;
                for(int task=0;task<3;task++){
                    if(task==last) continue;
                    int current=arr[day][task]+dp[day-1][task];
                    dp[day][last]=max(dp[day][last],current);
                }
            }
        }
        
        return dp[n-1][3];
        
    }
    
    int maximumPointsMemoryOptimize(vector<vector<int>>& arr){
        int n=arr.size();
        vector<int> currentDP(4);
        currentDP[0]=max(arr[0][1],arr[0][2]);
        currentDP[1]=max(arr[0][0],arr[0][2]);
        currentDP[2]=max(arr[0][0],arr[0][1]);
        currentDP[3]=max(arr[0][0],max(arr[0][1],arr[0][2]));
        
        for(int day=1;day<n;day++){
            vector<int> temp(4);
            for(int last=0;last<4;last++){
                for(int task=0;task<3;task++){
                    if(task==last) continue;
                    int curr=arr[day][task]+currentDP[task];
                    temp[last]=max(temp[last],curr);
                }
            }
            currentDP=temp;
        }
        
        return currentDP[3];
    }
  public:
    
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        // return maximumPointsMemo(arr);
        // return maximumPointsTabulation(arr);
        return maximumPointsMemoryOptimize(arr);
    }
};




int main() {
    Solution sol;
    vector<vector<int>> arr = {
        {1, 2, 5},
        {3, 1, 1},
        {3, 3, 3}
    };
    cout << sol.maximumPoints(arr) << endl;
    return 0;
}
