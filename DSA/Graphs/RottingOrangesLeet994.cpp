//Rotting Oranges LeetCode994  - https://leetcode.com/problems/rotting-oranges/description/
// There are 3 types of values in cells 0,1,2  
// 2 indicates rotten oranges , 1 indicates fine oranges , 0 indicates no orange
// every rotten orange can rott another orange in one second (vertical and horizontal neighbour )
//Implement BFS as there can be multiple oranges simultaneously rotting neighbours can't use DFS
//


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:


    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int m=grid.size();
        int n=grid[0].size();
        int unvisited=m*n;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    --unvisited;
                    q.push(make_pair(0,make_pair(i,j)));
                }else if (grid[i][j]==0)
                {
                    --unvisited;
                }
                
            }
        }


        int delRow[]={1,0,-1,0};
        int delCol[]={0,1,0,-1};
        int maxTime=0;
        while(!q.empty()){
            int time=q.front().first;
            if(time>maxTime){
                maxTime=time;
            }
            pair<int,int> node=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nRow= node.first + delRow[i];
                int nCol=node.second + delCol[i];

                cout<<"nRow: "<<nRow<<" nCol: "<<nCol<<endl;

                if(nRow>=0 && nRow<m && nCol>=0 && nCol <=n && grid[nRow][nCol]==1){
                    --unvisited;
                    grid[nRow][nCol]=2;
                    q.push(make_pair(time+1,make_pair(nRow,nCol)));
                }
            }

            cout << "Time: " << time << ", Queue: ";
            queue<pair<int, pair<int, int>>> tempQ = q;
            while (!tempQ.empty()) {
                auto elem = tempQ.front();
                tempQ.pop();
                cout << "(" << elem.first << ", (" << elem.second.first << ", " << elem.second.second << ")) ";
            }
            cout << endl;


            
    }
            return ((unvisited==0)?maxTime:-1);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,2}};
    int result = sol.orangesRotting(grid);
    cout << "Minimum time required to rot all oranges: " << result << endl;
    cout << "Final grid state:" << endl;
    for (const auto& row : grid) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    return 0;
}