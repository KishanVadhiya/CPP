// leetcode url - https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

#include<iostream>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        unordered_map<TreeNode*,TreeNode*> umap;
        vector<int> ans;
        q.push(root);
        while(!q.empty()){
            TreeNode* current=q.front();
            q.pop();

            if(current->left){
                umap[current->left]=current;
                q.push(current->left);
            }
            if(current->right){
                umap[current->right]=current;
                q.push(current->right);
            }

        }

        q.push(target);
        unordered_set<TreeNode*> visited;
        int lvl=0;
        while(!q.empty() && lvl<k){
            int n=q.size();
            lvl++;
            for(int i=0;i<n;i++){
                TreeNode* current=q.front();
                q.pop();
                visited.insert(current);
                if(current->left && visited.find(current->left)==visited.end()){
                    q.push(current->left);
                }
                if(current->right && visited.find(current->right)==visited.end()){
                    q.push(current->right);
                }
                if(umap.find(current)!=umap.end() && visited.find(umap[current])==visited.end()){
                    q.push(umap[current]);
                }
            }

        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};


int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;
    int k = 2;
    TreeNode* target = root->left; // target is node with value 5

    vector<int> result = sol.distanceK(root, target, k);

    cout << "Nodes at distance " << k << " from target node " << target->val << " are: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}