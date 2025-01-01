// GFG url - https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-distinct-islands

// important note - here we can not use unordered set as it uses hashmaps and vector<> are not hashable

// In this question we need to find number of distinct islands 
// Note - An duplicate island should be exact replica 
#include<iostream>
#include<vector>
#include<set>
using namespace std;


class Solution {
  public:
    void dfs(int i,int j,vector<vector<int>>& grid, vector<vector<int>> &visited,int startRow,int startCol,vector<pair<int,int>> &island,int m,int n){
        visited[i][j]=1;
        int delRow[]={0,1,0,-1};
        int delCol[]={1,0,-1,0};
        island.push_back(make_pair(i-startRow,j-startCol));
        for(int x=0;x<4;x++){

            int nRow=i+delRow[x];
            int nCol=j+delCol[x];

            if(nRow>=0 && nCol>=0 && nRow<m && nCol<n && grid[nRow][nCol] && !visited[nRow][nCol] ){
                dfs(nRow,nCol,grid,visited,startRow,startCol,island,m,n);
            }
            
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        set<vector<pair<int,int>>> s;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    vector<pair<int,int>> temp;
                    dfs(i,j,grid,visited,i,j,temp,m,n);
                    s.insert(temp);

                    for(auto it : temp) {
                        cout << "(" << it.first << ", " << it.second << ") ";
                    }
                    cout << endl;
                }
            }
        }

        return s.size();

    }
};


int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1}
    };

    Solution obj;
    int result = obj.countDistinctIslands(grid);
    cout << "Number of distinct islands: " << result << endl;

    return 0;
}