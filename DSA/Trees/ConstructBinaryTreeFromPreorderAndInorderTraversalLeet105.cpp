// leetcode url - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include<iostream>
#include<functional>
#include<unordered_map>
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
TreeNode* connectTree(vector<int>&preorder,int preSt,int preEnd, int inSt,int inEnd,unordered_map<int,int> &umap){
    if(preSt>preEnd || inSt>inEnd) return NULL;

    TreeNode* root=new TreeNode(preorder[preSt]);

    int inRoot= umap[root->val];
    int nodesLeft=inRoot-inSt;
    root->left=connectTree(preorder,preSt+1,preSt+nodesLeft,inSt,inRoot-1,umap);
    root->right=connectTree(preorder,preSt+nodesLeft+1,preEnd,inRoot+1,inEnd,umap);

    return root;
}
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> umap;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            umap[inorder[i]]=i;
        }
        return connectTree(preorder,0,n-1,0,n-1,umap);
    }
};


int main() {
    Solution sol;
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = sol.buildTree(preorder, inorder);

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