// leetcode url - https://leetcode.com/problems/binary-search-tree-iterator/
#include<iostream>
#include<stack>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class BSTIterator {
stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        s.push(root);
        root=root->left;
        while(root){
            s.push(root);
            root=root->left;
        }
    }
    
    int next() {
        TreeNode* node=s.top();
        s.pop();
        int ans = node->val;
        node=node->right;
        while(node){
            s.push(node);
            node=node->left;
        }
        return ans;
    }
    
    bool hasNext() {
        return s.size()>=1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    BSTIterator* obj = new BSTIterator(root);
    while (obj->hasNext()) {
        cout << obj->next() << " ";
    }

    // Clean up memory
    delete obj;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}