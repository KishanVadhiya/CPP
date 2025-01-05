// gfg link - https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        int src=1;
        vector<vector<pair<int,int>>> adj(n+1);
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1,1e9);
        vector<int> parent(n+1);
        for(int i=0;i<n+1;i++) parent[i]=i; 

        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }

        pq.push({0,src});

        while(!pq.empty()){
            int weigth=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int newWeight=it.second;
                int newNode=it.first;

                if(dist[newNode]>weigth+newWeight){
                    dist[newNode]=weigth+newWeight;
                    parent[newNode]=node;
                    pq.push({dist[newNode],newNode});
                }
            }
        }

        if(parent[n]==n){
            return vector<int>{-1};
        }

        vector<int> ans;
        ans.push_back(n);
        int currentParent=n;
        while(currentParent != src){
            currentParent=parent[currentParent];
            ans.push_back(currentParent);
            // cout<<"Loop"<<endl;
        }
        ans.push_back(dist[n]);
        reverse(ans.begin(),ans.end());
        return ans;


    }
};


int main() {
    int n = 2; // Number of nodes
    int m = 1; // Number of edges
    vector<vector<int>> edges = {
        {1, 2, 2},
        // {1, 4, 1},
        // {2, 4, 3},
        // {2, 5, 10},
        // {3, 1, 4},
        // {4, 3, 2},
        // {4, 5, 2}
    };


    Solution obj;
    vector<int> result = obj.shortestPath(n, m, edges);

    cout << "Shortest path from node 1 to node " << n << " is: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}