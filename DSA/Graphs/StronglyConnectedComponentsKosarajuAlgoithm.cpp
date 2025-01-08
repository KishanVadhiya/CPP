// gfg url - https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=strongly-connected-components-kosarajus-algo

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
private: 
    void reverseEdges(vector<vector<int>>& adj){
        int n=adj.size();
        vector<vector<int>> revAdj(n);
        for(int i=0;i<n;i++){
            for(auto it: adj[i]){
                revAdj[it].push_back(i);
            }
        }

        adj=revAdj;
    }
    void dfsWithStack(int node,vector<vector<int>>& adj,vector<int> &visited,stack<int> &s){
        visited[node]=true;

        for(auto it:adj[node]){
            if(!visited[it]){
                dfsWithStack(it,adj,visited,s);
            }
        }
        s.push(node);
    }

    void dfs(int node,vector<vector<int>>& adj,vector<int> &visited){
        visited[node]=true;
        cout<<" -->"<<node;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited);
            }
        }
    }
public:
    int kosaraju(vector<vector<int>> &adj)
    {
        // code here
        int n=adj.size();
        vector<int> visited(n,0);
        stack<int> s;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfsWithStack(i,adj,visited,s);
            }
        }
        visited.assign(n,0);

        reverseEdges(adj);

        for(int i = 0; i < adj.size(); i++) {
            cout << i << ": ";
            for(auto it : adj[i]) {
            cout << it << " ";
            }
            cout << endl<<endl;
        }

        stack<int> tempStack = s;
        cout << "Stack content: ";
        while (!tempStack.empty()) {
            cout << tempStack.top() << " ";
            tempStack.pop();
        }
        cout << endl<<endl;
        int cnt=0;
        while(!s.empty()){
            int node=s.top();
            s.pop();
            if(visited[node]) continue;
            visited[node]=1;
            cout<<"Connected component : "<<cnt++<<endl;
            dfs(node,adj,visited);
            cout<<endl;
        }

        return cnt;

    }
};


int main() {
    vector<vector<int>> adj = {
        {1},
        {2},
        {0, 3},
        {4},
        {}
    };

    Solution sol;
    int numSCC = sol.kosaraju(adj);
    cout << "Number of Strongly Connected Components: " << numSCC << endl;

    return 0;
}