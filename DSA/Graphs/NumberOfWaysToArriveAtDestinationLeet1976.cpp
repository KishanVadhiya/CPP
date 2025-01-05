// leet code url - https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=1e9+7;
        vector<long> dist(n,LONG_MAX);
        vector<long> ways(n);
        priority_queue<pair<long,int>,vector<pair<long,int>>,greater<pair<long,int>>> pq;
        vector<vector<pair<int,int>>> adj(n);
        dist[0]=0;

        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        ways[0]=1;
        pq.push({0,0});

        while(!pq.empty()){

            long weight=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto it:adj[node]){
                int newNode=it.first;
                long newWeight=weight+it.second;


                if(newWeight<dist[newNode]){
                    ways[newNode]=ways[node];
                    pq.push({newWeight,newNode});
                    dist[newNode]=newWeight;
                }else if(newWeight==dist[newNode]){
                    ways[newNode]=(ways[newNode]+ways[node])%mod;
                }

            }
        }
        return ways[n-1]%mod;

    }
};

int main() {
    Solution sol;
    int n = 7;
    vector<vector<int>> roads = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
    cout << "Number of ways to arrive at destination: " << endl << sol.countPaths(n, roads) << endl;
    return 0;
}