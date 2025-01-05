// https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

// this is using BFS but can be done using dijkstra algo

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(n==1 && grid[0][0]==0) return 1;
        // cout<<n<<endl;
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        vector<vector<int>> visited(n,vector<int>(n));
        visited[0][0]=1;
        while(!q.empty()){
            int weight=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();
            for(int x=-1;x<=1;x++){
                    int r=i+x;
                    if(r<0 || r>=n) continue;
                for(int y=-1;y<=1;y++){
                    int c= j+y;
                    if(c>=0 && c<n && grid[r][c]==0 && visited[r][c]==0){
                        if(r==n-1 && c==n-1) return weight+1;
                        visited[r][c]=1;
                        q.push({weight+1,{r,c}});
                        
                    }
                }
            }
        }

        return -1;
    }
};