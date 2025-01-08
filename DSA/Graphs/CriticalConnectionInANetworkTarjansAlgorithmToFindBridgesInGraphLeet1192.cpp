// leetcode url - https://leetcode.com/problems/critical-connections-in-a-network/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int timer=1;
    vector<vector<int>> ans;
private:
    void dfs(int node,int parent,vector<vector<int>>& adj,vector<int>& time,vector<int> &lowestTime,vector<int> &visited){
        cout<<"Current node: "<<node<<" parent: "<<parent<<endl;
        visited[node]=true;
        lowestTime[node]=timer;
        time[node]=timer++;
        for(auto it:adj[node]){
            if(it==parent) continue;
            if(!visited[it]){
                dfs(it,node,adj,time,lowestTime,visited);
            }

            lowestTime[node]=min(lowestTime[it],lowestTime[node]);
            if(lowestTime[it]>time[node]){
                // cout<<"Got critical edge"<<endl;
                ans.push_back(vector<int>{node,it});
                // cout<<"ans : "<<endl;
                // for(auto it:ans){
                //     cout<<it[0]<<" "<<it[1]<<endl;
                // }
            }

        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> time(n);
        vector<int> lowestTime(n);
        vector<int> visited(n,0);
        dfs(0,-1,adj,time,lowestTime,visited);
        cout<<"lowestTime : "<<endl;
        for(auto it:lowestTime){
            cout<<it<<" ";
        }
        cout<<endl;
        return ans;
    }
};




int main() {
    Solution sol;
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    vector<vector<int>> result = sol.criticalConnections(n, connections);

    cout << "Critical Connections: " << endl;
    for (const auto& conn : result) {
        cout << "[" << conn[0] << ", " << conn[1] << "]" << endl;
    }

    return 0;
}