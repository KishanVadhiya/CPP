// leetcode url - https://leetcode.com/problems/recover-binary-search-tree/description/
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
TreeNode* first=nullptr ,*second=nullptr, *prev=nullptr,*middle=nullptr;
void inorder(TreeNode* current){
    if(current==nullptr || second) return ;
    inorder(current->left);
    if(prev && prev->val>current->val){
        if(first==nullptr){
            first=prev;
            middle=current;
        }else{
            second=current;
        }
    }
    prev=current;
    inorder(current->right);
}
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        if(second==nullptr) second=middle;
        swap(first->val,second->val);
    }
};


int main() {
    // Create a sample tree: 
    //       3
    //      / \
    //     1   4
    //        /
    //       2
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    // Print the tree before recovery
    cout << "Before recovery: " << endl;
    cout << root->val << " " << root->left->val << " " << root->right->val << " " << root->right->left->val << endl;

    Solution sol;
    sol.recoverTree(root);

    // Print the tree after recovery
    cout << "After recovery: " << endl;
    cout << root->val << " " << root->left->val << " " << root->right->val << " " << root->right->left->val << endl;

    // Clean up memory
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}