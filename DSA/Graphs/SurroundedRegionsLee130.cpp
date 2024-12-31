// Surrounded Region Leet url - https://leetcode.com/problems/surrounded-regions/


#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<char>>& board,vector<vector<int>> &visited,int i,int j){
        int m=board.size();
        int n=board[i].size();
        visited[i][j]=1;
        int delRow[]={0,1,0,-1};
        int delCol[]={-1,0,1,0};

        for(int x=0;x<4;x++){
            int nRow= i + delRow[x];
            int nCol= j + delCol[x];

            if(nRow>=0 && nCol>=0 && nRow<m && nCol<n && board[nRow][nCol]=='O' && !visited[nRow][nCol] ){
                dfs(board,visited,nRow,nCol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            if(board[0][i]=='O') dfs(board,visited,0,i);
            if(board[m-1][i]=='O') dfs(board,visited,m-1,i);
        }
        for(int i=0;i<m;i++){
            if(board[i][0]=='O') dfs(board,visited,i,0);
            if(board[i][n-1]=='O') dfs(board,visited,i,n-1);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // cout<<visited[i][j]<<" ";
                if(!visited[i][j]){
                    board[i][j]='X';
                }
            }
            // cout<<endl;
        }
    }
};


int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    sol.solve(board);

    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}