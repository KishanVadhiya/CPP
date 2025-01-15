// gfg url - https://www.geeksforgeeks.org/problems/floor-in-bst/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-bst
#include<iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution{
int floorVal=-1;
void find(TreeNode* root,int x){
    if(root==nullptr) return ;
    if(x>=root->val){
        floorVal=max(floorVal,root->val);
        find(root->right,x);
    }else find(root->left,x);
}
public:
    int floor(TreeNode* root, int x) {
        // Code here
        find(root,x);
        return floorVal;
        
    }
};

int main() {
    Solution sol;

    // Creating a sample BST
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(4);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    int x = 5;
    cout << "Floor value of " << x << " in BST is: " << sol.floor(root, x) << endl;

    // Free allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}