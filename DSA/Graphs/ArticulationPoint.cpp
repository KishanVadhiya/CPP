// gfg url - https://www.geeksforgeeks.org/problems/articulation-point-1/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=articulation-point

#include<iostream>
#include<vector>

using namespace std;

class Solution {
    int timer=1;
    private:
    void dfs(int node,int parent,vector<int> &visited,vector<int> &time,vector<int> &lowestTime,vector<int> & mark,vector<int> adj[]){
        int child=0;
        visited[node]=1;
        time[node]=lowestTime[node]=timer++;
        for(auto it:adj[node]){
            if(it==parent) continue;
            if(!visited[it]){
                dfs(it,node,visited,time,lowestTime,mark,adj);
                lowestTime[node]=min(lowestTime[node],lowestTime[it]);
                if(lowestTime[it]>=time[node] && parent!=-1){
                    mark[node]=1;
                }
            child++;
            }else{
                lowestTime[node]=min(lowestTime[node],time[it]);
            }

        }
        if(child>1 && parent==-1){
            mark[node]=1;
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> time(V);
        vector<int> lowestTime(V);
        vector<int> mark(V,0);
        vector<int> visited(V,0);

        dfs(0,-1,visited,time,lowestTime,mark,adj);

        vector<int> ans;

        for(int i=0;i<V;i++){
            if(mark[i]) ans.push_back(i);
        }
        if(ans.size()==0) ans.push_back(-1);
        
        return ans;

    }
};


int main() {
    int V = 5;
    vector<int> adj[V];

    // Example graph
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(3);

    Solution obj;
    vector<int> result = obj.articulationPoints(V, adj);

    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}