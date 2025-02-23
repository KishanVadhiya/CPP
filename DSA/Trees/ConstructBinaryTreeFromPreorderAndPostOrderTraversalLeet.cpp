// leetcode url -https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
#include<iostream>
#include<vector>
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
    TreeNode* construct(int &preIdx,int &postIdx,vector<int>& preorder,vector<int>& postorder){
        TreeNode* root=new TreeNode(preorder[preIdx]);
        preIdx++;
        if(root->val!=postorder[postIdx]){
            root->left=construct(preIdx,postIdx,preorder,postorder);
        }

        if(root->val!=postorder[postIdx]){
            root->right=construct(preIdx,postIdx,preorder,postorder);
        }

        postIdx++;

        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preIdx=0;
        int postIdx=0;
        return construct(preIdx,postIdx,preorder,postorder);
    }
};

int main() {
    Solution sol;
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};
    
    TreeNode* root = sol.constructFromPrePost(preorder, postorder);
    
    // Function to print the tree in inorder traversal
    function<void(TreeNode*)> printInorder = [&](TreeNode* node) {
        if (node == nullptr) return;
        printInorder(node->left);
        cout << node->val << " ";
        printInorder(node->right);
    };
    
    printInorder(root);
    cout << endl;
    
    return 0;
}