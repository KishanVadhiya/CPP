// leetcode url - https://leetcode.com/problems/binary-tree-postorder-traversal/

#include<iostream>
#include<vector>
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

class Solution {
    vector<int> ans;
        void morrisPostorder(TreeNode* current){
        while(current!=nullptr){
            if(current->left==nullptr){
                ans.push_back(current->val);
                current=current->right;
            }else{
                TreeNode* prev=current->left;

                while(prev->right && prev->right!=current){
                    prev=prev->right;
                }

                if(prev->right==nullptr){
                    prev->right=current;
                    ans.push_back(current->val);
                    current=current->left;
                }else{
                    prev->right=nullptr;
                    current=current->right;
                }
            }
        } 
    }
    
    
public:
    vector<int> postorderTraversal(TreeNode* root) {
        morrisPostorder(root);
        return ans;
    }
};


int main() {
    // Create a sample tree: 
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<int> result = sol.postorderTraversal(root);

    // Print the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up the allocated memory
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}