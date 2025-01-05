// leet url - https://leetcode.com/problems/network-delay-time/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,1e9);
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        dist[k]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});

        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto it:adj[node]){
                int newNode=it.first;
                int newWt=wt+it.second;
                if(newWt<dist[newNode]){
                    dist[newNode]=newWt;
                    pq.push({newWt,newNode});
                }
            }
        }
        int ans=0;
        for(int i=1;i<n+1;i++){
            if(dist[i]==1e9) return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4;
    int k = 2;
    int result = sol.networkDelayTime(times, n, k);
    cout << "The network delay time is: " << result << endl;
    return 0;
}