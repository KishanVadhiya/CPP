// leetcode url - https://leetcode.com/problems/course-schedule-ii/

// we have an prerequisites array in which element[1] should come before element[0]
// if not possible return 0
// if possible return any valid order

// using dfs here using topological sort 

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    bool dfs(int node,vector<vector<int>>&adj,vector<int> &inPath,stack<int> &s){
        inPath[node]=2;

        for(auto it:adj[node]){
            if(inPath[it]==-1){
                if(dfs(it,adj,inPath,s)==false) return false;
            }else if(inPath[it]==2){
                return false;
            }
        }

        inPath[node]=1;
        s.push(node);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inPath(numCourses,-1);
        stack<int> s;
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        for(int i=0;i<numCourses;i++){
            if(inPath[i]==-1){
                if(dfs(i,adj,inPath,s)==false) return vector<int>();
            }
        }

        vector<int> ans;

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;


    }
};

int main() {
    Solution sol;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    vector<int> order = sol.findOrder(numCourses, prerequisites);

    if (order.empty()) {
        cout << "There is no possible order to finish all courses." << endl;
    } else {
        cout << "The order to finish all courses is: ";
        for (int course : order) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}