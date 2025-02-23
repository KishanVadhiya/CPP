// leetcode url - https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

#include<iostream>
#include<unordered_map>
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
TreeNode* connectTree(vector<int>& postorder,int postSt,int postEnd,int inSt,int inEnd,unordered_map<int,int> &umap){
    if(postSt>postEnd || inSt>inEnd) return nullptr;

    TreeNode* root=new TreeNode(postorder[postEnd]);
    int inRoot=umap[root->val];
    int nodesLeft=inRoot-inSt;

    root->left=connectTree(postorder,postSt,postSt+nodesLeft-1,inSt,inRoot-1,umap);
    root->right=connectTree(postorder,postSt+nodesLeft,postEnd-1,inRoot+1,inEnd,umap);

    return root;
}
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> umap;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            umap[inorder[i]]=i;
        }
        return connectTree(postorder,0,n-1,0,n-1,umap);
    }
};


int main() {
    Solution sol;
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    
    TreeNode* root = sol.buildTree(inorder, postorder);
    
    // Function to print the tree in inorder fashion
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