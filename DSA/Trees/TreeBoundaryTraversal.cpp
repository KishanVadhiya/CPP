// gfg url - https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

#include<iostream>
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
vector<int> ans;
    void leftBoundary(TreeNode* current){
        if(current->left==nullptr && current->right==nullptr) return;
        ans.push_back(current->val);
        if(current->left) leftBoundary(current->left);
        else leftBoundary(current->right);
    }
    
    void rightBoundary(TreeNode* current){
        if(current->left==nullptr && current->right==nullptr) return;
        if(current->right) rightBoundary(current->right);
        else rightBoundary(current->left);
        ans.push_back(current->val);
    }
    
    void leaf(TreeNode* current){
        if(current==nullptr) return;
        if(current->left==nullptr && current->right==nullptr) ans.push_back(current->val);
        leaf(current->left);
        leaf(current->right);
    }
  public:
    vector<int> boundaryTraversal(TreeNode *root) {
        // code here
        ans.push_back(root->val);
        if(root->left){
        leftBoundary(root->left);
        leaf(root->left);    
        }
        if(root->right){
        leaf(root->right);
        rightBoundary(root->right);
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
    vector<int> result = sol.boundaryTraversal(root);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}