#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    vector<vector<int>> ans;
    void levelOrderBFS(TreeNode* root) {
        if(root==nullptr) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> lvl;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* current=q.front();
                lvl.push_back(current->val);
                q.pop();
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
            ans.push_back(lvl);
        }
    }

    void BFSUsingDFS(TreeNode* root,int lvl){
        if(root==nullptr) return ;
        if(ans.size()==lvl) ans.push_back(vector<int>());
        ans[lvl].push_back(root->val);
        BFSUsingDFS(root->left,lvl+1);
        BFSUsingDFS(root->right,lvl+1);

    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>level;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}