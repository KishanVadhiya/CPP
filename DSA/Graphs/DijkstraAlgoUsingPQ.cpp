// gfg url - https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// Using Priority Queue or Min Heap
// doesn't work on negative weights
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;

        int n=adj.size();
        vector<int> dist(n,1e9);

        dist[src]=0;
        pq.push(make_pair(0,src));
        while(!pq.empty()){
          int d=pq.top().first;
          int node=pq.top().second;
          pq.pop();

          for(auto it:adj[node]){
            int edgeWeight=it.second;
            int adjNode=it.first;

            if(d+edgeWeight<dist[adjNode]){
              dist[adjNode]=d+edgeWeight;
              pq.push(make_pair(dist[adjNode],adjNode));
            }
          }
          
        }

        return dist;
    }
};



int main() {
  int V = 2;
  vector<vector<pair<int, int>>> adj(V);

  adj[0].push_back(make_pair(1, 9));

  Solution obj;
  vector<int> dist = obj.dijkstra(adj, 0);

  for (int i = 0; i < dist.size(); i++) {
    cout << "Distance from source to vertex " << i << " is " << dist[i] << endl;
  }

  return 0;
}
