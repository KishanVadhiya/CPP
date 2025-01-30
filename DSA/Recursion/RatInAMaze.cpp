// gfg url - https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
    vector<string> ans;
    int delRow[4]={0,1,0,-1};
    int delCol[4]={1,0,-1,0};
    void recur(vector<vector<int>> &arr,string &s,int i,int j,int m,int n){
        if(i==m-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        arr[i][j]=0;
        
        for(int x=0;x<4;x++){
            int nRow=i+delRow[x];
            int nCol=j+delCol[x];
            
            if(nRow>=0 && nCol>=0 && nRow<m && nCol<n && arr[nRow][nCol]){
                if(x==0) s+="R";
                else if(x==1) s+="D";
                else if(x==2) s+="L";
                else s+="U";
                recur(arr,s,nRow,nCol,m,n);
                s.pop_back();
            }
        }
        arr[i][j]=1;
    }
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // code here
        if(mat[0][0]==0) return ans;
        string s;
        int m=mat.size();
        int n=mat[0].size();
        recur(mat,s,0,0,m,n);
        return ans;
    }
};

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {1, 1, 1, 1}
    };
    
    Solution obj;
    vector<string> result = obj.findPath(maze);
    
    if(result.empty()) {
        cout << "No path found" << endl;
    } else {
        for(const string &path : result) {
            cout << path << endl;
        }
    }
    
    return 0;
}