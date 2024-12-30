#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> dfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        int V=adj.size();
        int start = 0;
        vector<bool> visited(V);
        vector<int> dfs;
        stack<int> s;
        s.push(start);
        visited[start]=true;
        
        while(!s.empty()){
            int node=s.top();
            s.pop();
            dfs.push_back(node);

            for(auto it:adj[node]){
                if(!visited[it]){
                    s.push(it);
                    visited[it]=true;
                }
            }
            
        }

        return dfs;
        
}

void dfs_recur(int currentNode,vector<bool> &visited,vector<int> &dfs,vector<vector<int >> &adj){
    
    
    dfs.push_back(currentNode);
    for(auto it:adj[currentNode]){
        if(!visited[it]){
            visited[it]=true;
            dfs_recur(it,visited,dfs,adj);
        }
    }

    
}

vector<int> dfsOfGraphRecur(vector<vector<int >> &adj){
    int V=adj.size();
    int startNode=0;
    vector<bool> visited(V);
    vector<int> dfs;
    visited[startNode]=true;

    dfs_recur(startNode,visited,dfs,adj);

    return dfs;
}


int main(){
    vector<vector<int> > adj={
        {1,2},
        {0,4,5},
        {0,3,6},
        {2,7},
        {1},
        {1},
        {2,7},
        {3,6}
    };

    // vector<int> result= dfsOfGraph(adj);
    vector<int> result = dfsOfGraphRecur(adj);

    for(auto it : result){
        cout<<it<<" ";
    }

    return 0;
}