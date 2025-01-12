// leetcode url- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
TreeNode* LCA=nullptr;
bool isAncestor(TreeNode* root,TreeNode* p,TreeNode* q){
    if(LCA!=nullptr || root==nullptr) return false;


    bool ifLeft=isAncestor(root->left,p,q);
    bool ifRight=isAncestor(root->right,p,q);

    if(ifLeft && ifRight || ((root==p || root==q)&&(ifLeft || ifRight))){
        LCA=root;
    }
    return ifLeft || ifRight || root==p || root==q;
}
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || root==p || root==q){
            return root;
        }
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);

        if(left==nullptr) return right;
        else if(right==nullptr) return left;
        else return root;
    }
};


int main() {
    // Create a sample tree
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
    TreeNode* p = root->left; // Node with value 5
    TreeNode* q = root->right; // Node with value 1

    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
    if (lca != nullptr) {
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    } else {
        cout << "Lowest Common Ancestor not found" << endl;
    }

    // Clean up memory
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}