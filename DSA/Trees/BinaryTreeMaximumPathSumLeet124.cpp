// leetcode url - https://leetcode.com/problems/binary-tree-maximum-path-sum/

#include<iostream>
#include<vector>
#include<algorithm>
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
int ans;
public:
    int dfs(TreeNode* root){
        if(root==nullptr) return -1e9;
        int left=dfs(root->left);
        int right=dfs(root->right);
        ans=max({ans,root->val,left+right+root->val,left+root->val,right+root->val});

        return max(root->val,root->val + max(left,right));
    }
    int maxPathSum(TreeNode* root) {
        ans=root->val;
        dfs(root);
        return ans;
    }
};

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(-4);
    root->left->right = new TreeNode(-5);
    root->right->left = new TreeNode(-6);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "Maximum Path Sum: " << sol.maxPathSum(root) << endl;

    // Clean up the allocated memory
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}