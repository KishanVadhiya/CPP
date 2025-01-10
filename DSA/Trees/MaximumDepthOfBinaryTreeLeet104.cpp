// leetcode url - https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

#include<iostream>
#include<vector>
#include<queue>
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
    int maxDepthDFS(TreeNode* root) {
        if(root==nullptr) return 0;

        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
    int maxDepthBFS(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            ans++;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* current=q.front();
                q.pop();
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
        }
        return ans;
        
    }
    int maxDepth(TreeNode* root) {
        return maxDepthDFS(root);
        // return maxDepthBFS(root);
    }
};


int main() {
    // Create a sample tree: 
    //       3
    //      / \
    //     9  20
    //       /  \
    //      15   7
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "Maximum Depth (DFS): " << sol.maxDepthDFS(root) << endl;
    cout << "Maximum Depth (BFS): " << sol.maxDepthBFS(root) << endl;

    // Clean up the allocated memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}