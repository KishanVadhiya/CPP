// gfg url - https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1

#include<iostream>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
void find(TreeNode* current,int &ceil,int &input){
    if(current==nullptr) return;
    
    if(current->val>=input){
        ceil=current->val;
        find(current->left,ceil,input);
    }else{
        find(current->right,ceil,input);
    }
    
    
    
}
// Function to return the ceil of given number in BST.
int findCeil(TreeNode* root, int input) {
    if (root == NULL) return -1;
    int ceil=-1;
    find(root,ceil,input);
    return ceil;
    // Your code here
}


int main() {
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(4);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    int input = 5;
    int ceil = findCeil(root, input);
    if (ceil == -1) {
        cout << "Ceil of " << input << " doesn't exist in the BST" << endl;
    } else {
        cout << "Ceil of " << input << " is " << ceil << endl;
    }

    return 0;
}