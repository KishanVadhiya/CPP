// GFG url - https://www.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states

#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution
{
private:
    bool dfs(int Node,vector<int> adj[],vector<int> &InPath,set<int> &ans){
        InPath[Node]=1;

        for(auto it:adj[Node]){
            if(InPath[it]==-1){
                if(dfs(it,adj,InPath,ans)==false) return false;;
            }else if(InPath[it]==1){
                return false;
            }
        }

        ans.insert(Node);
        InPath[Node]=0;
        return true;
    }
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        // code here
        set<int> ans;
        vector<int> InPath(V,-1);

        for(int i=0;i<V;i++){
            if(InPath[i]==-1)
            dfs(i,adj,InPath,ans);
        }

        return vector<int>(ans.begin(),ans.end());
    }
};

int main() {
    int V = 7;
    vector<int> adj[V];

    adj[0] = {1, 2};
    adj[1] = {2, 3};
    adj[2] = {5};
    adj[3] = {0, 4};
    adj[4] = {};
    adj[5] = {};
    adj[6] = {4, 5};

    Solution sol;
    vector<int> safeNodes = sol.eventualSafeNodes(V, adj);

    cout << "Safe nodes are: ";
    for (int node : safeNodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}