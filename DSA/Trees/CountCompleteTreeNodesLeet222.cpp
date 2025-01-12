// leetcode url - https://leetcode.com/problems/count-complete-tree-nodes/

#include<iostream>
#include<math.h>
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
    int leftHeight(TreeNode* current){
        if(current==nullptr) return 0;
        return 1+leftHeight(current->left);
    }
    int rightHeight(TreeNode* current){
        if(current==nullptr) return 0;
        return 1+rightHeight(current->right);
    }
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int lHeight=leftHeight(root);
        int rHeight=rightHeight(root);
        if(lHeight==rHeight) return pow(2,lHeight)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};


int main() {
    Solution sol;
    
    // Create a sample tree: 
    //        1
    //       / \
    //      2   3
    //     / \  /
    //    4  5 6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    cout << "Number of nodes in the complete binary tree: " << sol.countNodes(root) << endl;

    // Clean up memory
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}