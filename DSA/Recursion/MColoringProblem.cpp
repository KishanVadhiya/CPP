// gfg url - https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    vector<int> colorNode;
    bool isPossible(vector<vector<int>> &adj,int node,int color){
        for(auto it:adj[node]){
            if(colorNode[it]==color) return false;
        }
        return true;
    }
    bool recur(vector<vector<int>> &adj,int node,int m,int v){
        if(node==v) return true;
        for(int i=1;i<=m;i++){
            if(isPossible(adj,node,i)){
                colorNode[node]=i;
                if(recur(adj,node+1,m,v)) return true;
                colorNode[node]=0;
            }
        }
        return false;
        
    }
  public:
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        // code here
        vector<vector<int>> adj(v);
        for(auto it:edges){
            adj[it.first].push_back(it.second);
            adj[it.second].push_back(it.first);
        }
        
        vector<int> temp(v);
        colorNode=temp;
        
        return recur(adj,0,m,v);
    }
};


int main() {
    Solution sol;
    int v = 4; // Number of vertices
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 2}, {1, 3}}; // Edges of the graph
    int m = 3; // Number of colors

    if(sol.graphColoring(v, edges, m)) {
        cout << "Graph can be colored with " << m << " colors." << endl;
    } else {
        cout << "Graph cannot be colored with " << m << " colors." << endl;
    }

    return 0;
}