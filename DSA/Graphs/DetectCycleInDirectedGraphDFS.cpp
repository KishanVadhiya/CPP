// gfg url - https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph

//Detect cycle in directed graph using DFS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    private:
        bool dfs(int Node,vector<vector<int>>& adj,vector<int> &visited,vector<int> &path){
            visited[Node]=1;
            path[Node]=1;
            for(auto it:adj[Node]){
                if(!visited[it]){
                    if(dfs(it,adj,visited,path)) return true;
                }else if(visited[it] && path[it]){
                    return true;
                }
            }
            path[Node]=0;
            return false;
        }
    public:
    // Function to detect cycle in a directed graph.
        bool isCyclic(int V, vector<vector<int>> adj) {
            // code here
            vector<int> visited(V,0);
            vector<int> path(V,0);
            for(int i=0;i<V;i++){
                if(!visited[i]){
                    if(dfs(i,adj,visited,path)) return true;
                }
            }
            return false;
        }
};

class Solution2 {
    private:
        bool dfs(int Node,vector<vector<int>>& adj,vector<int> &inPath){
            inPath[Node]=1;
            for(auto it:adj[Node]){
                if(inPath[it]==-1){
                    if(dfs(it,adj,inPath)) return true;
                }else if(inPath[it]){
                    return true;
                }
            }
            inPath[Node]=0;
            return false;
        }
    public:
    // Function to detect cycle in a directed graph.
        bool isCyclic(int V, vector<vector<int>> adj) {
            // code here
            vector<int> inPath(V,-1);
            for(int i=0;i<V;i++){
                if(inPath[i]==-1){
                    if(dfs(i,adj,inPath)) return true;
                }
            }
            return false;
        }
};


int main() {
    int V = 4; // Number of vertices
    vector<vector<int>> adj(V);

    // Example graph with a cycle
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);

    Solution2 obj;
    if (obj.isCyclic(V, adj)) {
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "Graph does not contain a cycle" << endl;
    }

    return 0;
}