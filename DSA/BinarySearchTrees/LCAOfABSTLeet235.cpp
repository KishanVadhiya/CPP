// leetcode url - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
TreeNode* LCA=nullptr;
void dfs(TreeNode *current,TreeNode *p,TreeNode *q){
    // cout<<"Did do a dfs"<<endl;
    // cout<<(current==nullptr)<<endl;
    // cout<<(current->val > q->val)<<endl;
    // cout<<(current->val < p->val)<<endl;
    if(current==nullptr ) return ;
    if(current->val>=p->val && current->val<=q->val)    LCA=current;
    // cout<<"At node : "<<current->val<<endl;
    if(q->val<current->val) dfs(current->left,p,q);
    if(p->val>current->val) dfs(current->right,p,q);
}
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val>q->val) dfs(root,q,p);
        else dfs(root,p,q);

        return LCA;
    }
};

int main() {
    Solution sol;

    // Create a sample BST
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    TreeNode* p = root->left; // Node with value 2
    TreeNode* q = root->right; // Node with value 8

    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
    if (lca != nullptr) {
        cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is " << lca->val << endl;
    } else {
        cout << "Lowest Common Ancestor not found" << endl;
    }

    // Clean up the allocated nodes
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}