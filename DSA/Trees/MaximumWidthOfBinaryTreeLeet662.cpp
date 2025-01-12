// leetcode url - https://leetcode.com/problems/maximum-width-of-binary-tree/

#include<iostream>
#include<queue>
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

public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long>> q;
        long ans=0;
        q.push({root,0});

        while(!q.empty()){
            int n=q.size();
            long mmin=q.front().second;
            long first,last;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front().first;
                long curIdx=q.front().second-mmin;
                q.pop();
                if(i==0) first=curIdx;
                if(i==n-1) last=curIdx;
                if(node->left) q.push({node->left,2*curIdx+1});
                if(node->right) q.push({node->right,2*curIdx+2});
            }
            ans=max(ans,last-first+1);
        }

        return ans;
    }
};


int main() {
    Solution sol;

    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    // Call the function and print the result
    int width = sol.widthOfBinaryTree(root);
    cout << "Maximum width of the binary tree is: " << width << endl;

    // Clean up the allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}