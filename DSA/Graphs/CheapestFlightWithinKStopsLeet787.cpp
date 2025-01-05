// leet url - https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        vector<int> dist(n,1e9);
        dist[src]=0;
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,pair<int,int>>> pq;

        pq.push({0,{src,0}});

        while(!pq.empty()){
            int currentStop=pq.front().first;
            int weight=pq.front().second.second;
            int node=pq.front().second.first;
            pq.pop();
            if(currentStop>k) continue;

            for(auto it:adj[node]){
                int adjNode=it.first;
                int adjW=it.second;

                if((weight+adjW<dist[adjNode]) && k>=currentStop){
                    dist[adjNode]=weight+adjW;
                    pq.push({currentStop+1,{adjNode,dist[adjNode]}});
                }
            }
        }
        for (int i = 0; i < dist.size(); ++i) {
            cout << "dist[" << i << "] = " << dist[i] << endl;
        }

        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};



int main() {
    Solution sol;
    int n = 4;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    int src = 0;
    int dst = 3;
    int k = 1;
    int result = sol.findCheapestPrice(n, flights, src, dst, k);
    cout << "The cheapest price is: " << result << endl;
    return 0;
}