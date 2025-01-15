// leet url - https://leetcode.com/problems/validate-binary-search-tree/
#include<iostream>
#include<climits>
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
    bool isValid(TreeNode* root,long upper,long lower){
        if(root==nullptr) return true;
        if(root->val>=upper || root->val<=lower) return false;

        return isValid(root->left,root->val,lower) && isValid(root->right,upper,root->val);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root,LONG_MAX,LONG_MIN);
    }
};

int main() {
    Solution solution;

    // Create a sample binary search tree
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    // Validate the BST
    if (solution.isValidBST(root)) {
        cout << "The tree is a valid BST." << endl;
    } else {
        cout << "The tree is not a valid BST." << endl;
    }

    // Clean up memory
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}