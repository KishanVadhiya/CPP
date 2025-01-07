#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

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
    int removeStones(vector<vector<int>>& stones) {
        int maxRow=0;
        int maxCol=0;
        for(auto it:stones){
            maxRow=max(maxRow,it[0]);
            maxCol=max(maxCol,it[1]);
        }
        maxRow++;
        maxCol++;

        DisjointSet ds(maxRow+maxCol);

        for(auto it:stones){
            int r=it[0];
            int c=maxRow+it[1];
            ds.UnionBySize(r,c);
        }


        int ans=0;
        unordered_map<int,int> umap;
        for(int i=0;i<maxRow+maxCol;i++){
            umap[ds.findUltimateParent(i)]++;
        }


        for(auto it:umap){
            if(it.second!=1){
                ans++;
            }
        }

        return stones.size()-ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    cout << "Maximum number of stones that can be removed: " << sol.removeStones(stones) << endl;
    return 0;
}