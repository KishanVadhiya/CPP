#include <iostream>
#include <vector>
#include <queue>

//time complexity O(V) + O(E)
//

using namespace std;
// This is for starting from node 0
vector<int> BFS(int V, vector<int> graph[], int start=0) {
    vector<bool> visited(V);
    visited[start]=1;
    vector<int> bfs;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        bfs.push_back(node);
        q.pop();
        for(auto it: graph[node]){
            if(!visited[it]){
                q.push(it);
                visited[it]=true;
            }
        }

    }


    return bfs;
}

int main() {
    int nodes = 5;
    vector<int> graph[nodes];

    // Sample graph
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0};
    graph[3] = {1};
    graph[4] = {1};

    int startNode = 0;
    vector<int> result = BFS(nodes, graph,1);

    // Print the result
    for (int node : result) {
        cout << node << " ";
    }



    return 0;
}