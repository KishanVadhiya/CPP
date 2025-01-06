// letcode url - https://leetcode.com/problems/number-of-provinces/description/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
private:
    int UltimateParentKrushkal(int node, vector<int> &parent) {
        if (node == parent[node]) return node;
        return parent[node] = UltimateParentKrushkal(parent[node], parent);
    }

    void UnionKrushkal(int node1, int node2, vector<int> &parent) {
        int UltimateParentNode1 = UltimateParentKrushkal(node1, parent);
        int UltimateParentNode2 = UltimateParentKrushkal(node2, parent);

        if (UltimateParentNode1 == UltimateParentNode2) return;

        parent[UltimateParentNode2] = UltimateParentNode1;
    }

public:
    int findCircleNumKrushkal(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> parent(n);

        for (int i = 0; i < n; i++) parent[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j]) {
                    UnionKrushkal(i, j, parent);
                }
            }
        }

        for (int i = 0; i < n; i++) UltimateParentKrushkal(i, parent);

        return (unordered_set<int>(parent.begin(), parent.end())).size();
    }

    int findCircleNum(vector<vector<int>>& graph) {
        return findCircleNumKrushkal(graph);
    }
};

int main() {
    Solution solution;
    vector<vector<int>> graph = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    int numProvinces = solution.findCircleNum(graph);
    cout << "Number of Provinces: " << numProvinces << endl;

    return 0;
}
