// Leet url -https://leetcode.com/problems/find-eventual-safe-states/
// BFS is most important approach

// as BFS kahn's algo in topological sort works in indegree and terminal has 0 outdegree we need to reverse the graph then we will be able to indentify all the nodes connected to the terminal and are safe

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
class Solution {
private: 
    bool dfs(int node,vector<vector<int>>& adj,vector<int>& inPath){
        inPath[node]=2;

        cout<<endl<<"Currently in node : "<<node<<endl;

        for(auto it:adj[node]){
            if(inPath[it]==0){
                if(!dfs(it,adj,inPath)) return false;
            }else if(inPath[it]==2){
                return false;
            }
        }
        inPath[node]=1;
        return true;
    }
public:
    vector<int> eventualSafeNodesDFS(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> inPath(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
            cout<<"Started dfs from the node : "<<i<<endl;
            if(!inPath[i]){
                dfs(i,graph,inPath);
            }
            if(inPath[i]==1){
                ans.push_back(i);
            }
        }

        cout << "inPath: ";
        for(int i = 0; i < n; i++) {
            cout << inPath[i] << " ";
        }
        cout << endl;



        return ans;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        queue<int> q;
        int n=graph.size();
        vector<vector<int>> revGraph(n);
        vector<int> indegree(n);

        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                revGraph[it].push_back(i);
                ++indegree[i];
            }
        }

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto it:revGraph[node]){
                --indegree[it];
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                ans.push_back(i);
            }
        }

        return ans;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> safeNodes = sol.eventualSafeNodes(graph);

    cout << "Safe nodes are: ";
    for(int node : safeNodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}