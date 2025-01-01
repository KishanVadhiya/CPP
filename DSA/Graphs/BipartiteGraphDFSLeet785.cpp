// leet url - https://leetcode.com/problems/is-graph-bipartite/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int> &visited,vector<int>& colors,int Node,int color){
        visited[Node]=1;
        colors[Node]=color;

        for(auto it:graph[Node]){
            if(!visited[it]){
                if(dfs(graph,visited,colors,it,!color)==false) return false;;
            }else if(colors[it]==color){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,0);
        vector<int> colors(n);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(dfs(graph,visited,colors,i,0)==false) return false;;
            }
        }
        return true;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> graph = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    if(sol.isBipartite(graph)) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}