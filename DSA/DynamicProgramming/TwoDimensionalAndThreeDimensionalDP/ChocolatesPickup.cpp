// gfg url - https://www.geeksforgeeks.org/problems/chocolates-pickup/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=chocolates-pickup
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
    int delC[3]={-1,0,+1};
    int recur(int i,int j1,int j2,vector<vector<int>>& arr,vector<vector<vector<int>>>& dp,int m,int n){
        if(j1<0 || j2<0 || j1>=n || j2>=n) return INT_MIN;
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        if(i==m-1){
            if(j1==j2) return dp[i][j1][j2]=arr[i][j1];
            return dp[i][j1][j2]=arr[i][j1]+arr[i][j2];
        }

        int ans=INT_MIN;
        for(auto x:delC){
            for(auto y:delC){
                ans=max(ans,recur(i+1,j1+x,j2+y,arr,dp,m,n));
            }
        }
        
        if(j1==j2){
            return dp[i][j1][j2]=ans+arr[i][j1];
        }else{
            return dp[i][j1][j2]=ans+arr[i][j1]+arr[i][j2];
        }
    }

    int memoization(int m,int n,vector<vector<int>>& arr){
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
        int ans=recur(0,0,n-1,arr,dp,m,n);
        // for(int i=0;i<m;i++){
        //     cout<<"For i: "<<i<<endl;
        //     for(auto it:dp[i]){
        //         for(auto x:it){
        //             cout<<x<<" ";
        //         }
        //         cout<<endl;
        //     }
        //     cout<<endl;
        // }

        return ans;

    }

    int tabulation(int m,int n,vector<vector<int>>& arr){
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n)));

        for(int j1=0;j1<n;j1++){
            for(int j2=0;j2<n;j2++){
                if(j1==j2){
                    dp[m-1][j1][j2]=arr[m-1][j1];
                }else{
                    dp[m-1][j1][j2]=arr[m-1][j1]+arr[m-1][j2];
                }
            }
        }
        // cout<<"Reached here "<<endl;
        for(int i=m-2;i>=0;i--){
            for(int j1=0;j1<n;j1++){
                for(int j2=0;j2<n;j2++){
                    int ans=INT_MIN;
                    for(auto x:delC){
                        for(auto y:delC){
                            if(j1+x<0 || j2+y<0 || j1+x>=n || j2+y>=n) continue;
                            ans=max(ans,dp[i+1][j1+x][j2+y]);
                        }
                    }
                    if(j1==j2){
                        dp[i][j1][j2]=arr[i][j1]+ans;
                    }else{
                        dp[i][j1][j2]=arr[i][j1]+arr[i][j2]+ans;
                    }
                }
 
            }
        }

        return dp[0][0][n-1];
    }

    int memoryOptimization(int m,int n,vector<vector<int>>& arr){
        vector<vector<int>> dp(n,vector<int>(n));

        for(int j1=0;j1<n;j1++){
            for(int j2=0;j2<n;j2++){
                if(j1==j2){
                    dp[j1][j2]=arr[m-1][j1];
                }else{
                    dp[j1][j2]=arr[m-1][j1]+arr[m-1][j2];
                }
            }
        }

        for(int i=m-2;i>=0;i--){
            vector<vector<int>> temp(n,vector<int>(n));

            for(int j1=0;j1<n;j1++){
                for(int j2=0;j2<n;j2++){
                    int ans=INT_MIN;
                    for(auto x:delC){
                        for(auto y:delC){
                            if(j1+x<0 || j2+y<0 || j1+x>=n || j2+y>=n) continue;
                            ans=max(ans,dp[j1+x][j2+y]);
                        }
                    }

                    if(j1==j2){
                        temp[j1][j2]=arr[i][j1]+ans;
                    }else{
                        temp[j1][j2]=arr[i][j1]+arr[i][j2]+ans;
                    }
                }
            }

            dp=temp;
        }

        return dp[0][n-1];
    }
  public:
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        
        // return memoization(n,m,grid);
        // return tabulation(n,m,grid);
        return memoryOptimization(n,m,grid);
        
    }
};


int main() {
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    Solution sol;
    int n = grid.size();
    int m = grid[0].size();
    cout << "Maximum chocolates collected: " << sol.solve(n, m, grid) << endl;
    return 0;
}