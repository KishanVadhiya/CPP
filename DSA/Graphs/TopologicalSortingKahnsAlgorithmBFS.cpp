#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
private:
    void bfs(vector<vector<int>>& adj,vector<int> &indegree,queue<int> q,vector<int> &ans){
        while(!q.empty()){
            int Node=q.front();
            q.pop();
            ans.push_back(Node);

            for(auto it:adj[Node]){
                --indegree[it];
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
    }
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>> &adj)
    {
        int n=adj.size();
        vector<int> ans;
        queue <int> q;
        vector<int> indegree(n,0);

        for(int i=0;i<n;i++){
            for(auto n:adj[i]){
                ++indegree[n];
            }
        }

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        bfs(adj,indegree,q,ans);
        return ans;
    }
};

int main() {
    // Create a graph given in the above diagram
    vector<vector<int>> adj(8);
    adj[6].push_back(3);
    adj[7].push_back(3);
    adj[6].push_back(5);
    adj[3].push_back(5);
    adj[7].push_back(1);
    adj[1].push_back(2);

    Solution obj;
    vector<int> result = obj.topologicalSort(adj);
    
    cout << "Topological Sort of the given graph is: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
