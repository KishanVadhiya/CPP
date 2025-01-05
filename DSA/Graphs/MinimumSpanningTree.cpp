// gfg link - https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        vector<pair<int,int>> MST;
        priority_queue<vector<int>, vector<vector<int>>,greater<vector<int>>> pq;
        pq.push(vector<int>{0,0,-1});
        vector<int> visited(V);
        int sum=0;
        while(!pq.empty()){
            vector<int> t=pq.top();
            pq.pop();
            int wt=t[0];
            int node=t[1];
            int parentNode=t[2];
 
            if(visited[node])   continue;
            
            visited[node]=1;
            if(parentNode!=-1) {
            MST.push_back({node,parentNode});
            }
            sum+=wt;
            

            for(auto it:adj[node]){
                int adjNode=it[0];
                int adjWt=it[1];
                if(!visited[adjNode]){
                    pq.push(vector<int>{adjWt,adjNode,node});
                }
            }
        }

        cout << "Edges in the Minimum Spanning Tree:" << endl;
        for(auto edge : MST) {
            cout << edge.second << " - " << edge.first << endl;
            
        }
        return sum;
    }
};


int main() {
    int V = 5;
    vector<vector<int>> adj[V];

    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});
    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[4].push_back({1, 5});
    adj[4].push_back({2, 7});

    Solution obj;
    int sum = obj.spanningTree(V, adj);
    cout << "Sum of weights of edges of the Minimum Spanning Tree: " << sum << endl;

    return 0;
}