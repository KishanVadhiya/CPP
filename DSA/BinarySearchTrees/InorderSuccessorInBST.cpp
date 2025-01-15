// gfg url - https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1

#include<iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
bool foundX=false;
int  successor=-1;
void inorder(TreeNode* current,TreeNode* x){
    if(current==nullptr) return ;
    if(current->val>x->val){
        successor=current->val;
        inorder(current->left,x);
    }else{
        inorder(current->right,x);
    }
}
void leftMost(TreeNode* current){
    while(current->left){
        current=current->left;
    }
    successor=current->val;
}
  public:
    // returns the inorder successor of the TreeNode x in BST (rooted at 'root')
    int inOrderSuccessor(TreeNode *root, TreeNode *x) {
        // Your code here
        if(x->right){
            leftMost(x->right);
        }else{
            inorder(root,x);
        }
            return successor;
    }
};


int main() {
    // Create a sample BST
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(12);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);

    Solution sol;
    TreeNode* x = root->left->right; // Node with value 12
    int successor = sol.inOrderSuccessor(root, x);
    cout << "Inorder Successor of " << x->val << " is " << successor << endl;

    // Clean up memory
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}