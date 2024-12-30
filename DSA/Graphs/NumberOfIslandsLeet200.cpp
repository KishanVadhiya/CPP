//We need to find number of islands in a matrix of m*n 
//It looks like matrix problem but is a graphs problem 
//we can perform bfs or dfs and find neighbouring land

// in leetcode it is island only if it has land vertically and horizonatally url - https://leetcode.com/problems/number-of-islands/
// in geeksforgeeks it is island in diagonals also url - https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void dfs(vector<vector<char>> &grid,int i,int j,int m,int n){        //Leetcode apporach
    grid[i][j]='0';
    if(i-1>=0 && grid[i-1][j]=='1'){
        dfs(grid,i-1,j,m,n);
    }
    if(i+1<m && grid[i+1][j]=='1'){
        dfs(grid,i+1,j,m,n);
    }
    if(j-1>=0 && grid[i][j-1]=='1'){
        dfs(grid,i,j-1,m,n);
    }
    if(j+1<n && grid[i][j+1]=='1'){
        dfs(grid,i,j+1,m,n);
    }
}

void printGrid(vector<vector<char>> &grid){
    for(auto it1:grid){
        for(auto it2:it1){
            cout<<it2<<" ";
        }
        cout<<endl;
    }
}

int numIslands(vector<vector<char>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    // vector<vector> visited((m>n)?m:n,0);
    int ans=0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1'){
                ans+=1;
                dfs(grid,i,j,m,n);

            printGrid(grid);
            }
            cout<<endl;
        }
    }
        
    return ans;
        
    }



int main(){
    vector<vector<char>> grid = {
        {'0', '1'},
        {'1', '0'},
        {'1', '1'},
        {'1', '0'}
    };

    cout<<numIslands(grid);


}



// GFG apporach 
class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int delrow = -1; delrow <= 1; delrow++) {
                for (int delcol = -1; delcol <= 1; delcol++) {
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                        grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cnt;
    }
};