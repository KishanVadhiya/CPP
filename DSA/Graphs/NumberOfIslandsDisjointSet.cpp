// gfg url - https://www.geeksforgeeks.org/problems/number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-islands

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
private:
    int ultimateParent(int node,vector<int> &parent){
        if(node==parent[node]) return node;
        return parent[node]=ultimateParent(parent[node],parent);
    }
    void unionSet(int node1,int node2,vector<int> &parent){
        int ultimateParentNode1=ultimateParent(node1,parent);
        int ultimateParentNode2=ultimateParent(node2,parent);

        if(ultimateParentNode1==ultimateParentNode2) return ;

        parent[ultimateParentNode2]=ultimateParentNode1;
    }
public:
    
    vector<int> numOfIslands(int m, int n, vector<vector<int>> &operators)
    {
        vector<int> parent(n*m);
        for(int i=0;i<m*n;i++) parent[i]=i;

        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<int> num;

        int delRow[]={0,1,0,-1};
        int delCol[]={-1,0,1,0};
        int ans=0;
        for(auto it:operators){

            int row=it[0];
            int col=it[1];
            if(visited[row][col]){
                num.push_back(ans);
                continue;
            }
            visited[row][col]=1;
            int node1=row*n+col;
            ans++;
            for(int k=0;k<4;k++){
                int nRow=row+delRow[k];
                int nCol=col+delCol[k];

                if(nRow>=0 && nCol>=0 && nRow<m && nCol<n && visited[nRow][nCol]){

                    int node2=nRow*n+nCol;
                    int ultimateParentNode1=ultimateParent(node1,parent);
                    int ultimateParentNode2=ultimateParent(node2,parent);

                    if(ultimateParentNode1!=ultimateParentNode2){

                        ans--;
                        unionSet(ultimateParentNode1,ultimateParentNode2,parent);
                    }
                }
            }
            num.push_back(ans);
            
        }
        return num;
    }
};


int main() {
    Solution sol;
    int n = 4, m = 5;
    vector<vector<int>> operators = {{1, 1}, {0, 1}, {3, 3}, {3, 4}};
    vector<int> result = sol.numOfIslands(n, m, operators);

    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}