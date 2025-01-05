// gfg link - https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-floyd-warshall

#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        int n=mat.size();
        // for(int i=0;i<)
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==-1){
                    mat[i][j]=1e9;
                }
                if(i==j){
                    mat[i][j]=0;
                }
            }
        }
        for(int via=0;via<n;via++){
            // vector<vector<int>> temp=mat;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(mat[i][j]==-1) mat[i][j]=1e9;
                    if(mat[i][via]!=1e9 && mat[via][j]!=1e9 && mat[i][j]>mat[i][via]+mat[via][j]){
                        mat[i][j]=mat[i][via]+mat[via][j];
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
              if(mat[i][i]!=0){
                  cout<<"Contains negative cycle"<<endl;
              }
            
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1e9){
                    mat[i][j]=-1;
                }
            }
        }

    }
};





int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {0, 3, -1, 7},
        {8, 0, 2, -1},
        {5, -1, 0, 1},
        {2, -1, -1, 0}
    };

    sol.shortestDistance(mat);

    cout << "The shortest distance matrix is:" << endl;
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}