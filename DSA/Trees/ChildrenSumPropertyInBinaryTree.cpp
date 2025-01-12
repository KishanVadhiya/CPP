#include<iostream>
#include <functional>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
    public:
    void childernSumProperty(TreeNode* root){
        if(root->left==nullptr && root->right==nullptr) return;

        if(root->left && root->val>root->left->val) root->left->val=root->val;
        if(root->right && root->val>root->right->val) root->left->val=root->val;

        if(root->left) childernSumProperty(root->left);
        if(root->right) childernSumProperty(root->right);

        int total=0;
        if(root->left) total+=root->left->val;
        if(root->right) total+=root->right->val;

        if(total>root->val) root->val=total;

    }
};



#include <queue>

int main() {
    TreeNode* root = new TreeNode(40);
    root->left = new TreeNode(10);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(2);
    // root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(30);
    root->right->right = new TreeNode(40);

    Solution sol;
    sol.childernSumProperty(root);

    // Print the tree level-wise
    if (root == nullptr) return 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl; // Change line after every level
    }
    cout << endl;

    return 0;
}