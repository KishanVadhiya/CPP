// leetcode url - https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
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
void dfs(TreeNode* current,int upperLimit,int lowerLimit,int &i,int n,vector<int>& preorder){
    if(i==n) return;
    if(preorder[i]<current->val && preorder[i]>lowerLimit){
        current->left=new TreeNode(preorder[i++]);
        dfs(current->left,current->val,lowerLimit,i,n,preorder);
    }
    if(i==n) return ;
    if(preorder[i]>current->val && preorder[i]<upperLimit){
        current->right=new TreeNode(preorder[i++]);
        dfs(current->right,upperLimit,current->val,i,n,preorder);
    }

}
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=new TreeNode(preorder[0]);
        int i=1;
        int n=preorder.size();

        dfs(root,INT_MAX,INT_MIN,i,n,preorder);
        return root;
    }
};


