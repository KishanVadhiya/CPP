#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    private:
        bool isCyclicKahnsAlgoBFS(int V,vector<vector<int>> adj){
            vector<int> indegree(V,0);
            queue<int> q;
            for(int i=0;i<V;i++){
                for(auto it:adj[i]){
                    ++indegree[it];
                }
            }

            for(int i=0;i<V;i++){
                if(!indegree[i]){
                    q.push(i);
                }
            }


            cout << "Initial indegree: ";
            for(int i = 0; i < V; i++) {
                cout << indegree[i] << " ";
            }
            cout << endl;

            cout << "Initial queue: ";
            queue<int> tempQ = q;
            while(!tempQ.empty()) {
                cout << tempQ.front() << " ";
                tempQ.pop();
            }
            cout << endl;

            int RemainingNodes=V;

            while(!q.empty()){
                int Node=q.front();
                q.pop();
                --RemainingNodes;

                for(auto it:adj[Node]){
                    --indegree[it];
                    if(indegree[it]==0){
                        q.push(it);
                    }
                }


            }

            return !(RemainingNodes==0);

        }
    public:
    // Function to detect cycle in a directed graph.
        
        
        
        bool isCyclic(int V, vector<vector<int>> adj){
            return isCyclicKahnsAlgoBFS(V,adj);
        }
};


int main() {
    int V = 4;
    vector<vector<int>> adj(V);
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(3);

    Solution obj;
    if(obj.isCyclic(V, adj)) {
        cout << "Graph contains cycle" << endl;
    } else {
        cout << "Graph doesn't contain cycle" << endl;
    }

    return 0;
}