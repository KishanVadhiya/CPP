
#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        set<pair<int,pair<int,int>>> q;
        int n=grid.size();
        if(n==1) return grid[0][0];
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        q.insert({grid[0][0],{0,0}});
        int delRow[]={0,-1,0,1};
        int delCol[]={1,0,-1,0};
        while(!q.empty()){
            auto it=*(q.begin());
            int wt=it.first;
            int i=it.second.first;
            int j=it.second.second;
            q.erase(it);
            int minWt=max(wt,grid[i][j]);
            if(i==n-1 && j==n-1) return minWt;
            for(int k=0;k<4;k++){
                int nRow=i+delRow[k];
                int nCol=j+delCol[k];
                if(nRow>=0 && nCol>=0 && nRow<n && nCol<n){
                int newWt=max(grid[nRow][nCol],minWt);
                if(newWt<dist[nRow][nCol]){
                    if(dist[nRow][nCol]!=1e9){
                        q.erase({dist[nRow][nCol],{nRow,nCol}});
                    }
                    dist[nRow][nCol]=newWt;
                    q.insert({dist[nRow][nCol],{nRow,nCol}});
                }
                    
                }
            }
        }

        return dist[n-1][n-1];
    }
};


int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {0, 2, 1},
        {1, 3, 2},
        {4, 5, 3}
    };
    cout << sol.swimInWater(grid) << endl;
    return 0;
}