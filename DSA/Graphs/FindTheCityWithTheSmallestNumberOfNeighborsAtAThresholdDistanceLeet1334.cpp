// leet url - https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Solution {
public:
    int findTheCityDijksta(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        vector<int> neighbours(n);
        for(int src=0;src<n;src++){
            vector<int> dist(n,1e9);
            dist[src]=0;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            pq.push({0,src});

            while(!pq.empty()){
                int wt=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                if(wt>distanceThreshold) break;

                for(auto it:adj[node]){
                    int newNode=it.first;
                    int newWt=it.second;
                    if(dist[newNode]>wt+newWt){
                        cout<<"Reached here";
                        dist[newNode]=wt+newWt;
                        pq.push({dist[newNode],newNode});
                    }
                }
            }

            cout << "Source: " << src << " Distances: ";
            for (int d : dist) {
                cout << d << " ";
            }
            cout << endl<<endl;

            for(int i=0;i<n;i++){
                if(dist[i]<=distanceThreshold && i!=src){
                    neighbours[src]++;
                }
            }
        }

        int ans=0;
        int ansNeighbour=1e9;

        for(int i = 0; i < n; i++) {
            cout << "City " << i << " has " << neighbours[i] << " neighbours within the distance threshold." << endl;
        }
        for(int i=0;i<n;i++){
            if(neighbours[i]<=ansNeighbour){
                ans=i;
                ansNeighbour=neighbours[i];
            }
        }
        return ans;
    }


    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n,vector<int>(n,1e9));
        for(auto edge:edges){
            if(edge[2]==-1) edge[2]=1e9;
            mat[edge[0]][edge[1]]=edge[2];
            mat[edge[1]][edge[0]]=edge[2];
        }
        for(int i=0;i<n;i++){
            mat[i][i]=0;
        }

        cout << "Initial distance matrix:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1e9) {
                cout << "INF ";
            } else {
                cout << mat[i][j] << " ";
            }
            }
            cout << endl;
        }


        // apply floyd warshall

        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(mat[i][via]==1e9 || mat[via][j]==1e9) continue;
                    mat[i][j]=min(mat[i][j],mat[i][via]+mat[via][j]);
                }
            }
        }

        cout << "Distance matrix after Floyd-Warshall:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1e9) {
                    cout << "INF ";
                } else {
                    cout << mat[i][j] << " ";
                }
            }
            cout << endl;
        }

        int city=-1;
        int neighboursOfCity=1e9;

        for(int i=0;i<n;i++){
            int neighbours=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]<=distanceThreshold){
                    neighbours++;
                }
            }
            if(neighbours<=neighboursOfCity){
                city=i;
                neighboursOfCity=neighbours;
            }
        }

        return city;
    }

    
};




int main() {
    Solution sol;
    int n = 4;
    vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int distanceThreshold = 4;
    int city = sol.findTheCity(n, edges, distanceThreshold);
    cout << "The city with the smallest number of neighbors at a threshold distance is: " << city << endl;
    return 0;
}