// Leet Code url - https://leetcode.com/problems/01-matrix/
// we need to find distance of 1 from the nearest 0
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,pair<int,int>>> q;
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push(make_pair(1,make_pair(i,j)));
                    visited[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            // Print the queue
            queue<pair<int,pair<int,int>>> tempQ = q;
            cout << "Queue: ";
            while (!tempQ.empty()) {
                auto front = tempQ.front();
                cout << "(" << front.first << ", (" << front.second.first << ", " << front.second.second << ")) ";
                tempQ.pop();
            }
            cout << endl;

            cout << "Visited Matrix:" << endl;
            for (const auto& row : visited) {
                for (int val : row) {
                    cout << val << " ";
                }
                cout << endl;
            }
            int distance=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();

            int delRow[]={0,1,0,-1};
            int delCol[]={1,0,-1,0};

            for(int x=0;x<4;x++){
                int nRow= i+delRow[x];
                int nCol= j+delCol[x];

                cout << "nRow: " << nRow << ", nCol: " << nCol << endl;

                if(nRow>=0 && nCol>=0 && nRow<m && nCol<n && !visited[nRow][nCol]){
                    visited[nRow][nCol]=1;
                    mat[nRow][nCol]=distance;
                    q.push(make_pair(distance+1,make_pair(nRow,nCol)));
                }
            }
        }

        cout<<"At the end visited Matrix"<<endl;
        for (const auto& row : visited) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
        cout<<endl<<endl;


        return mat;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> result = sol.updateMatrix(mat);

    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}