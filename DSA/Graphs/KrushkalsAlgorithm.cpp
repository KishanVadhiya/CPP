#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    private:
        int UltimateParentKrushkal(int Node,vector<int> &Parent){
                if(Node==Parent[Node]) return Parent[Node];
                return Parent[Node]=UltimateParentKrushkal(Parent[Node],Parent);
        }
        
        void UnionKrushkal(int Node1,int Node2, vector<int> &Parent){
                int UltimateParentNode1=UltimateParentKrushkal(Node1,Parent);
                int UltimateParentNode2=UltimateParentKrushkal(Node2,Parent);
                
                if(UltimateParentNode1==UltimateParentNode2) return ;
                
                Parent[UltimateParentNode2]=UltimateParentNode1;
        }

    public:
        int spanningTreeKrushkalAlgorithm(int V, vector<vector<int>> adj[]) {
                vector<int> Parent(V+1);
                for(int i=0;i<V+1;i++) Parent[i]=i;
                vector<pair<int,pair<int,int>>> MST;
                vector<pair<int,pair<int,int>>> edges;
                int WeightOfTree=0;
                for(int i=0;i<V;i++){
                        for(auto it:adj[i]){
                                int wt=it[1];
                                int node=i;
                                int adjNode=it[0];
                                edges.push_back({wt,{node,adjNode}});
                        }
                }

                sort(edges.begin(),edges.end());
                for(auto it:edges){
                        int node1=it.second.first;
                        int node2=it.second.second;
                        int wt=it.first;
                        if(UltimateParentKrushkal(node1,Parent)!=UltimateParentKrushkal(node2,Parent)){
                                UnionKrushkal(node1,node2,Parent);
                                WeightOfTree+=wt;
                                MST.push_back(it);
                        }
                }
                return WeightOfTree;
        }
        
        int spanningTree(int V, vector<vector<int>> adj[]) {
                return spanningTreeKrushkalAlgorithm(V,adj);
        }
};

int main() {
        int V = 5; // Number of vertices in the graph
        vector<vector<int>> adj[V];

        // Example graph
        adj[0].push_back({1, 2});
        adj[0].push_back({3, 6});
        adj[1].push_back({0, 2});
        adj[1].push_back({2, 3});
        adj[1].push_back({3, 8});
        adj[1].push_back({4, 5});
        adj[2].push_back({1, 3});
        adj[2].push_back({4, 7});
        adj[3].push_back({0, 6});
        adj[3].push_back({1, 8});
        adj[4].push_back({1, 5});
        adj[4].push_back({2, 7});

        Solution obj;
        int mst_weight = obj.spanningTree(V, adj);
        cout << "Weight of the Minimum Spanning Tree is: " << mst_weight << endl;

        return 0;
}
