// gfg url - https://www.geeksforgeeks.org/problems/largest-bst/1
#include<climits>
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
class NodeValue{
    public:
    int minimum,maximum,maxSize;
    NodeValue(int maximum,int minimum,int maxSize){
        this->minimum=minimum;
        this->maximum=maximum;
        this->maxSize=maxSize;
    }
};
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    NodeValue helper(TreeNode *root){
        if(root==nullptr) {
            return NodeValue(INT_MIN,INT_MAX,0);
        }
        
        NodeValue left=helper(root->left);
        NodeValue right=helper(root->right);
        
        if(root->val>left.maximum && root->val<right.minimum){
            return NodeValue(max(right.maximum,root->val),min(root->val,left.minimum),1+left.maxSize+right.maxSize);
        }else{
            return NodeValue(INT_MAX,INT_MIN,max(left.maxSize,right.maxSize));
        }
        
    }
    int largestBst(TreeNode *root)
    {
    	//Your code here
    	return helper(root).maxSize;
    }
};


int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "Size of the largest BST is: " << sol.largestBst(root) << endl;

    return 0;
}