// gfg url - https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// Using Set
// doesn't work on negative weights
#include<iostream>
#include<set>
#include<vector>

using namespace std;

class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        set<pair<int,int>> s;

        int n=adj.size();
        vector<int> dist(n,1e9);

        dist[src]=0;
        s.insert({0,src});

        while(!s.empty()){
            auto it= *s.begin();
            int d=it.first;
            int node=it.second;
            s.erase(it);

            for(auto it:adj[node]){
                int newNode=it.first;
                int newWeight=it.second;

                if(d+newWeight<dist[newNode]){
                    if(dist[newNode]!=1e9){
                        s.erase({dist[newNode],newNode});
                    }
                    dist[newNode]=d+newWeight;
                    s.insert({dist[newNode],newNode});
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
