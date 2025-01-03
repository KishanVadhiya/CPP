// gjg url - https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph-having-unit-distance

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n=adj.size();
        vector<int> dist(n,-1);
        dist[0]=0;
        queue<pair<int,int>> q;
        q.push(make_pair(src,0));

        while(!q.empty()){
            int node=q.front().first;
            int d=q.front().second;
            q.pop();
            for(auto it : adj[node]){
                if(dist[it]==-1){
                    q.push(make_pair(it,d+1));
                    dist[it]=d+1;
                }else{
                    dist[it]=min(dist[it],d+1);
                }

                
            }
     
        }

        return dist;    
    }
};




int main() {
    vector<vector<int>> adj = {{1, 3}, {0, 2}, {1, 6}, {0, 4}, {3, 5}, {4, 6}, {2, 5, 7, 8}, {6, 8}, {7, 6}};
    int src = 0;
    Solution obj;
    vector<int> result = obj.shortestPath(adj, src);

    for (int i = 0; i < result.size(); ++i) {
        cout << "Shortest distance from node " << src << " to node " << i << " is " << result[i] << endl;
    }

    return 0;
}
