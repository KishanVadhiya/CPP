#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
private: 
    void bfs(vector<vector<int>> &image,int sr,int sc,int color,int originalColor){
        std::cout<<originalColor<<endl;
        image[sr][sc]=color;
        queue<pair<int,int>> q;
        q.push(make_pair(sr,sc));
        int m=image.size();
        int n=image[0].size();

        int delRow[]={-1,0,1,0};
        int delCol[]={0,-1,0,1};

        vector<vector<int>> visited(m,vector<int>(n,0));
        visited[sr][sc]=1;

        while(!q.empty()){
            pair<int,int> pixel=q.front();
            q.pop();
            int i=pixel.first;
            int j=pixel.second;
            
            for(int z=0;z<4;z++){
                int nrow= i+ delRow[z];
                int ncol= j+ delCol[z];

                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && image[nrow][ncol]==originalColor && !visited[nrow][ncol]){
                    q.push(make_pair(nrow,ncol));
                    visited[nrow][ncol]=1;
                    image[nrow][ncol]=color;
                }
            }
            // if(i-1>=0 && !visited[i-1][j] && image[i-1][j]==originalColor){

            //     q.push(make_pair(i-1,j));
            //     image[i-1][j]=color;
            //     visited[i-1][j]=1;

            // }
            // if(i+1<m && !visited[i+1][j] && image[i+1][j]==originalColor){
            //     q.push(make_pair(i+1,j));
            //     image[i+1][j]=color;
            //     visited[i+1][j]=1;
            // }

            // if(j-1>=0 && !visited[i][j-1] && image[i][j-1]==originalColor){
            //     q.push(make_pair(i,j-1));
            //     image[i][j-1]=color;
            //     visited[i][j-1]=1;
            // }
            // if(j+1<n && !visited[i][j+1] && image[i][j+1]==originalColor){
            //     q.push(make_pair(i,j+1));
            //     image[i][j+1]=color;
            //     visited[i][j+1]=1;
            // }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        bfs(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc = 1, newColor = 2;

    vector<vector<int>> result = sol.floodFill(image, sr, sc, newColor);

    for (const auto& row : result) {
        for (const auto& pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}