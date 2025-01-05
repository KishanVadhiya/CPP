// gfg link - 

#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V,1e8);
        dist[src]=0;
        for(int i=0;i<V-1;i++){
            bool updated=false;
            for(auto edge:edges){
                
                if(dist[edge[0]]!=1e8 && dist[edge[1]]>(dist[edge[0]]+edge[2])){
                    dist[edge[1]]=dist[edge[0]]+edge[2];
                    updated=true;
        
                }
            }
            // if(!updated){
            //     break;
            // }
        }
        
        // to detect cycle;
        for(auto edge:edges){
            if(dist[edge[0]]!=1e8 && dist[edge[1]]>dist[edge[0]]+edge[2]){
                    return vector<int>{-1};
                }
        }
        return dist;
    }
};


int main() {
    int V = 5; // Number of vertices in the graph
    vector<vector<int>> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2},
        {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };
    int src = 0; // Source vertex

    Solution obj;
    vector<int> result = obj.bellmanFord(V, edges, src);

    if (result[0] == -1) {
        cout << "Graph contains negative weight cycle" << endl;
    } else {
        cout << "Vertex Distance from Source" << endl;
        for (int i = 0; i < V; ++i) {
            cout << i << "\t\t" << result[i] << endl;
        }
    }

    return 0;
}