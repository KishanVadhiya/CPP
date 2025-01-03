#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

class Solution {
    private:
    void dfs(int node,vector<vector<pair<int,int>>>& graph,stack<int>& s,vector<int>& visited){
        visited[node]=1;
        for(auto it:graph[node]){
            if(!visited[it.first])
            dfs(it.first,graph,s,visited);
        }
        s.push(node);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        stack<int> s;
        vector<vector<pair<int,int>>> adj(V);
        vector <int> visited(V);
        for(auto it:edges){
            adj[it[0]].push_back(make_pair(it[1],it[2]));
        }
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,s,visited);
            }
        }
        
        
        vector<int> dist(V,-1);
        dist[s.top()]=0;
        cout<<"Top node :"<<s.top()<<endl;
        while(!s.empty()){
            int node=s.top();
            s.pop();

            cout<<endl<<"Checking for Node: "<<node<<endl;
            
            for(auto it:adj[node]){
                if(dist[it.first]==-1){
                    dist[it.first]=dist[node]+ it.second;
                    cout<<"Initialized distance for node: "<<it.first<<" = "<<dist[it.first]<<endl;
                }else{
                    cout<<"Updated distance for node : "<<it.first;
                    dist[it.first] = min(dist[it.first],dist[node]+it.second);
                    cout<<" new distance is : "<<dist[it.first]<<endl;
                }
            }
        }
        
        return dist;
    }
};



int main() {
    int V = 7;
    int E = 8;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {1, 3, 1},
        {4, 0, 3},
        {4, 2, 1},
        {2, 3, 3},
        {6, 4, 2},
        {6, 5, 3},
        {5, 4, 1}
    };

    Solution obj;
    vector<int> result = obj.shortestPath(V, E, edges);

    for (int i = 0; i < result.size(); i++) {
        cout << "Shortest distance to node " << i << " is " << result[i] << endl;
    }

    return 0;
}