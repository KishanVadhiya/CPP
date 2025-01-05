// url - https://leetcode.com/problems/path-with-minimum-effort/description/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        dist[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});

        int delRow[]={0,1,0,-1};
        int delCol[]={1,0,-1,0};

        while(!pq.empty()){
            
            int weight=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            // cout<<"Node ->"<<" weight: "<<weight<<" i: "<<i<<" ,j: "<<j<<endl;
            if(i==m-1 && j==n-1) return weight;
            // as the priority queue will get the minimum weight for the corner node so no need for further calculations
            pq.pop();


            for(int x=0;x<4;x++){
                int nRow=i+delRow[x];
                int nCol=j+delCol[x];

                

                if(nRow>=0 && nCol>=0 && nRow<m && nCol<n ){
                    int newEffort=max(weight,(abs(heights[nRow][nCol]-heights[i][j])));
                    if(newEffort<dist[nRow][nCol]){
                        dist[nRow][nCol]=newEffort;
                        pq.push({newEffort,{nRow,nCol}});
                    }
                    
                }
                
            }

        }



        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }

        return dist[m-1][n-1];
    }
};


int main() {
    Solution sol;
    vector<vector<int>> heights = {
        {1, 10, 6, 7, 9, 10, 4, 9}
    };
    int result = sol.minimumEffortPath(heights);
    cout << "Minimum effort path: " << result << endl;
    return 0;
}