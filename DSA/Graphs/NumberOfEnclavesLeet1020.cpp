// Leet Code url - https://leetcode.com/problems/number-of-enclaves/
// need to find the islands that are not at boundary
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    void bfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited)
    {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        visited[i][j] = 1;
        while (!q.empty())
        {
            cout<<"Inside while"<<endl;
            int r = q.front().first;
            int c = q.front().second;

            int delRow[] = {0, 1, 0, -1};
            int delCol[] = {-1, 0, 1, 0};

            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nRow = r + delRow[i];
                int nCol = c + delCol[i];

                if (nRow >= 0 && nCol >= 0 && nRow < m && nCol < n && grid[nRow][nCol] == 1 && !visited[nRow][nCol])
                {
                    visited[nRow][nCol]=1;
                    q.push(make_pair(nRow,nCol));
                }
            }
        }
        for (int i = 0; i < visited.size(); i++)
        {
            for (int j = 0; j < visited[0].size(); j++)
            {
            cout << visited[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited)
    {
        int m = grid.size();
        int n = grid[i].size();
        visited[i][j] = 1;
        int delRow[] = {0, 1, 0, -1};
        int delCol[] = {-1, 0, 1, 0};

        for (int x = 0; x < 4; x++)
        {
            int nRow = i + delRow[x];
            int nCol = j + delCol[x];

            if (nRow >= 0 && nCol >= 0 && nRow < m && nCol < n && grid[nRow][nCol] == 1 && !visited[nRow][nCol])
            {
                dfs(nRow, nCol, grid, visited);
            }
        }
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            if (grid[0][i] == 1)
                bfs(0, i, grid, visited);
            if (grid[m - 1][i] == 1)
                bfs(m - 1, i, grid, visited);
        }
        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 1)
                bfs(i, 0, grid, visited);
            if (grid[i][n - 1] == 1)
                bfs(i, n - 1, grid, visited);
        }

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    ++ans;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};
    cout << "Number of Enclaves: " << sol.numEnclaves(grid) << endl;
    return 0;
}
