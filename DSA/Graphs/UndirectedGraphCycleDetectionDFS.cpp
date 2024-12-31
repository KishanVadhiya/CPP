// GFG link -https://leetcode.com/problems/rotting-oranges/description/



#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>> &adj){
        vector<int> visited(adj.size());
        for(int i=0;i<adj.size();i++){
            if(!visited[i]){
                if(dfs(adj,visited,i,-1)) return true;
            }
        }
        return false;
    };

    bool dfs(vector<vector<int>> &adj,vector<int> &visited,int Node,int prevNode){
        visited[Node]=true;

        for(auto it:adj[Node]){
            if(!visited[it]){
                if(dfs(adj,visited,it,Node)) return true;
            }else if(it!=prevNode){
                return true;
            }
        }
        return false;
    }
};


int main() {
    vector<vector<int>> adj(3);
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(0);
    adj[0].push_back(2);

    Solution obj;
    bool result = obj.isCycle(adj);
    if(result) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    return 0;
}