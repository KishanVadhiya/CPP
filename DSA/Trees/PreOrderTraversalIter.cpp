#include<iostream>
#include<stack>
#include<vector>
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
    void preOrderTraversalIter(TreeNode* root,vector<int> &ans){
        if(root == nullptr) return ;
        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty()){
            TreeNode* current=s.top();
            s.pop();
            ans.push_back(current->val);
            if(current-> right) s.push(current->right);
            if(current->left) s.push(current->left);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preOrderTraversalIter(root,ans);
        return ans;
    }
};


int main() {
    // Create a sample tree: 
    //     1
    //    / \
    //   2   3
    //  / \
    // 4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<int> result = sol.preorderTraversal(root);

    // Print the result
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up the allocated memory
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}


