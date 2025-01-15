// leetcode url - https://leetcode.com/problems/delete-node-in-a-bst/
#include<iostream>
#include<functional>
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
TreeNode* helper(TreeNode* root){
    if(root->left==nullptr) return root->right;
    else if(root->right==nullptr) return root->left;

    TreeNode* rightChild=root->right;
    TreeNode* lastRight=findLastRight(root->left);
    lastRight->right=rightChild;
    return root->left;
}

TreeNode* findLastRight(TreeNode* root){
    if(root->right==nullptr) return root;
    return findLastRight(root->right);
}
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return nullptr;
        if(root->val==key) return helper(root);
        TreeNode* dummy=root;
        while(root!=nullptr){
            if(key<root->val){
                if(root->left && root->left->val==key){
                    root->left=helper(root->left); 
                    break;
                }else{
                    root=root->left;
                }
            }else{
                if(root->right && root->right->val==key){
                    root->right=helper(root->right);
                    break;
                }else{
                    root=root->right;
                }
            }
        }
        return dummy;
    }
};



int main() {
    Solution sol;

    // Create a sample BST
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    int key = 3;
    root = sol.deleteNode(root, key);

    // Function to print the BST in-order
    function<void(TreeNode*)> inorder = [&](TreeNode* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    };

    inorder(root);
    cout << endl;

    return 0;
}