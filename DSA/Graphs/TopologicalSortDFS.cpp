// GFG url - https://www.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort
//Acyclic graph will be given
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
private:
    void dfs(vector<vector<int>> &adj,vector<int> &visited,stack<int> &s,int Node){
        visited[Node]=1;
        cout<<"At Node :"<<Node<<endl;
        for(auto it:adj[Node]){
            cout<<"Inside for loop"<<endl;
            if(!visited[it]){
                dfs(adj,visited,s,it);
            }
        }

        cout<<"Put :"<<Node<<" in stack"<<endl;

        s.push(Node);
    }
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>> &adj)
    {
        // Your code here
        int n=adj.size();
        stack<int> s;
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,visited,s,i);
            }
        }

        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
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

    cout << "The adjacency list of the graph is:" << endl;
    for (int i = 0; i < adj.size(); i++) {
        cout << i << ": ";
        for (int j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
    
    Solution obj;
    vector<int> result = obj.topologicalSort(adj);
    
    cout << "Topological Sort of the given graph is: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}