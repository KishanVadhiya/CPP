#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

//leetcode url - https://leetcode.com/problems/making-a-large-island/description/

class DisjointSet {
    public:
        vector<int> Size, Parent;
        DisjointSet(int n) {
            Size.resize(n + 1, 0);
            Parent.resize(n + 1);

            for (int i = 0; i < n + 1; i++) {
                Parent[i] = i;
                Size[i] = 1;
            }
        }

        int findUltimateParent(int node) {
            if (node == Parent[node]) return node;
            return Parent[node] = findUltimateParent(Parent[node]);
        }

        void UnionBySize(int node1, int node2) {
            int ultimateParentNode1 = findUltimateParent(node1);
            int ultimateParentNode2 = findUltimateParent(node2);

            if (ultimateParentNode1 == ultimateParentNode2) return;

            if (Size[ultimateParentNode1] > Size[ultimateParentNode2]) {
                Parent[ultimateParentNode2] = ultimateParentNode1;
                Size[ultimateParentNode1] += Size[ultimateParentNode2];
            } else if (Size[ultimateParentNode2] > Size[ultimateParentNode1]) {
                Parent[ultimateParentNode1] = ultimateParentNode2;
                Size[ultimateParentNode2] += Size[ultimateParentNode1];
            } else {
                Parent[ultimateParentNode2] = ultimateParentNode1;
                Size[ultimateParentNode1] += Size[ultimateParentNode2];
            }
        }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        int delRow[] = {0, 1, 0, -1};
        int delCol[] = {1, 0, -1, 0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                int currentNode = i * n + j;
                for (int k = 0; k < 4; k++) {
                    int nRow = i + delRow[k];
                    int nCol = j + delCol[k];

                    if (nRow >= 0 && nCol >= 0 && nRow < n && nCol < n && grid[nRow][nCol]) {
                        int adjNode = nRow * n + nCol;
                        ds.UnionBySize(currentNode, adjNode);
                    }
                }
            }
        }

        int ans = ds.Size[0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) continue;
                int temp = 0;
                unordered_set<int> visitedNode;
                for (int k = 0; k < 4; k++) {
                    int nRow = i + delRow[k];
                    int nCol = j + delCol[k];
                    if (nRow >= 0 && nCol >= 0 && nRow < n && nCol < n && grid[nRow][nCol]) {
                        int newNode = nRow * n + nCol;
                        if (visitedNode.find(ds.findUltimateParent(newNode)) != visitedNode.end()) continue;
                        int sizeOfIsland = ds.Size[ds.findUltimateParent(newNode)];
                        temp += sizeOfIsland;
                        visitedNode.insert(ds.findUltimateParent(newNode));
                    }
                }
                ans = max(ans, temp + 1);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{1, 0}, {0, 1}};
    cout << "Largest Island Size: " << sol.largestIsland(grid) << endl;
    return 0;
}
