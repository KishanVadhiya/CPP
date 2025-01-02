// leetcode url - https://leetcode.com/problems/course-schedule/

// we have an prerequisites array in which element[0] should come before element[1]
// if not possible return 0
// if possible return any valid order

// using kahn's algo here using topological sort 
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector< vector<int>> adj(numCourses);

        for(auto it:prerequisites){
            indegree[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }

        cout << "Graph adjacency list:" << endl;
        for (int i = 0; i < numCourses; ++i) {
            cout << i << ": ";
            for (auto it : adj[i]) {
            cout << it << " ";
            }
            cout << endl;
        }

        cout << "Indegree of each node:" << endl;
        for (int i = 0; i < numCourses; ++i) {
            cout << "Node " << i << ": " << indegree[i] << endl;
        }

        int removedCount=numCourses;

        queue <int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            cout<<"Inside while loop node : "<<node<<endl;
            --removedCount;
            for(auto it: adj[node]){
                --indegree[it];
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        cout<<removedCount<<endl;
        return removedCount==0;
    }
};

int main() {
    Solution sol;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    numCourses = 2;
    prerequisites = {{1, 0}};
    bool result = sol.canFinish(numCourses, prerequisites);
    cout << (result ? "Can finish all courses" : "Cannot finish all courses") << endl;
    return 0;
}