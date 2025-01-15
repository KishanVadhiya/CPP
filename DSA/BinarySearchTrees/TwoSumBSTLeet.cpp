// leetcode url - https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
bool isReverse;
public:
    BSTIterator(TreeNode* root,bool rev) {
        isReverse=rev;
        s.push(root);
        if(isReverse){
            root=root->right;
            while(root){
                s.push(root);
                root=root->right;
            }
        }else{
            root=root->left;
            while(root){
                s.push(root);
                root=root->left;
            }
        }
    }
    
    int next() {
        TreeNode* node=s.top();
        s.pop();
        int ans = node->val;
        if(isReverse){
            node=node->left;
            while(node){
                s.push(node);
                node=node->right;
            }
        }else{
        node=node->right;
        while(node){
            s.push(node);
            node=node->left;
        }
        }
        return ans;
    }
    
    bool hasNext() {
        return s.size()>=1;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator left=BSTIterator(root,false);
        BSTIterator right=BSTIterator(root,true);
        int a=left.next();
        int b=right.next();
        while(a<b){
            if(a+b==k) return true;
            else if(a+b>k) b=right.next();
            else a=left.next();
        }
        return false;
    }
};