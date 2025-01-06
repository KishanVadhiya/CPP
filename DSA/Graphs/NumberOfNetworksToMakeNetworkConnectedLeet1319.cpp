// leet url - https://leetcode.com/problems/number-of-operations-to-make-network-connected/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int ultimateParent(int node, vector<int> &parent) {
        if (node == parent[node]) return node;
        return parent[node] = ultimateParent(parent[node], parent);
    }

    void unionSet(int node1, int node2, vector<int> &parent) {
        int ultimateParentNode1 = ultimateParent(node1, parent);
        int ultimateParentNode2 = ultimateParent(node2, parent);

        if (ultimateParentNode1 != ultimateParentNode2) {
            parent[ultimateParentNode1] = ultimateParentNode2;
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        int numberOfExtraConnectionsAvailable = 0;
        int connectedComputers = 1;
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        for (auto it : connections) {
            int u = it[0];
            int v = it[1];

            if (ultimateParent(u, parent) != ultimateParent(v, parent)) {
                unionSet(u, v, parent);
            } else {
                numberOfExtraConnectionsAvailable++;
            }
        }
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (i == ultimateParent(i, parent)) ans++;
        }

        return (ans > numberOfExtraConnectionsAvailable) ? -1 : ans;
    }
};

int main() {
    Solution sol;
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}};
    cout << sol.makeConnected(n, connections) << endl;
    return 0;
}