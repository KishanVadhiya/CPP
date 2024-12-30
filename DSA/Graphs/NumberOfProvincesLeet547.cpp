// Leetcode 547 url - https://leetcode.com/problems/number-of-provinces/

// We need to find number of connected components in a graph

// can also be done via visited vector keeping track of it


// Time complexity = O(n*n) due to matrix representaion
// Space Complexity = O(n*n) due to matrix memory

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// void printSet(unordered_set<int> &uset){
//     cout<<endl;
//     for(const auto &it:uset){
//         cout<<it<<" ";
//     }
//     cout<<endl;
// }
void dfs(unordered_set<int> &unvisited,vector<vector<int>> & graph,int currentNode){

    unvisited.erase(currentNode);
    int n=graph.size();
    for(int elem=0;elem<n;elem++){
        if(graph[currentNode][elem] && (unvisited.find(elem)!= unvisited.end())){
            dfs(unvisited,graph,elem);
        }
    }
};

int findNumberOfProvinces(vector<vector<int>> &graph){
    int n=graph.size();
    unordered_set<int> unvisited;
    for(int i=0;i<graph.size();i++){
        unvisited.insert(i);
    }

    int ans=0;

    while(!unvisited.empty()){
        ans+=1;
        int node=*(unvisited.begin());
        dfs(unvisited,graph,node);



    }
    return ans;
}

int main(){
    vector<vector<int>> graph={
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };
    cout<<findNumberOfProvinces(graph);
}