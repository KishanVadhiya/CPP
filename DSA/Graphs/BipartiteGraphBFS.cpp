// GFG url -https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-distinct-islands


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
  public:
    
    bool isBipartite(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int> visited(n,0);
        vector<int> colors(n,0);
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                q.push(make_pair(i,0));
                visited[i]=1;
                colors[i]=0;
                while(!q.empty()){
                    int node=q.front().first;
                    int color=q.front().second;

                    q.pop();

                    for(auto it:adj[node]){
                        if(visited[it] && colors[it]==color){
                            return false;
                        }else if(!visited[it]){
                            q.push(make_pair(it,!color));
                            visited[it]=1;
                            colors[it]=!color;
                        }
                    }
                }
            }
        }

        return true;
        
    }
};


int main() {
    Solution sol;
    vector<vector<int>> adj = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };


    if (sol.isBipartite(adj)) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}