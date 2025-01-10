// leetcode url - https://leetcode.com/problems/symmetric-tree/

#include<iostream>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    bool dfs(TreeNode* current1,TreeNode* current2){
        if(current1==nullptr && current2==nullptr) return true;
        if((current1==nullptr && current2!=nullptr) || (current1!=nullptr && current2==nullptr) || current1->val!=current2->val) return false;

        return dfs(current1->left,current2->right) && dfs(current1->right,current2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left,root->right);
    }
};


int main() {
    Solution solution;

    // Create a symmetric tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    // Check if the tree is symmetric
    bool result = solution.isSymmetric(root);
    cout << (result ? "The tree is symmetric." : "The tree is not symmetric.") << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}