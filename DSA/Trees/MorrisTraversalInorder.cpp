// leetcode url - https://leetcode.com/problems/binary-tree-inorder-traversal/

#include<iostream>
#include<vector>
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
public:
    // void Inorder(TreeNode* current){
    //     if(current ==nullptr) return ;

    //     Inorder(current->left);
    //     ans.push_back(current->val);
    //     Inorder(current->right);
    // }
    // void InorderIter(TreeNode* root){
    //     if(root ==nullptr) return ;
    //     stack<TreeNode*> st;
    //     TreeNode* node=root;
    //     while(1){
    //         if(node!=nullptr){
    //             st.push(node);
    //             node=node->left;
    //         }else{
    //             if(st.empty()) break;
    //             node=st.top();
    //             st.pop();
    //             ans.push_back(node->val);
    //             node=node->right;
    //         }


    //     }
    // }
    void morrisInorder(TreeNode* current){
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
                    current=current->left;
                }else{
                    prev->right=nullptr;
                    ans.push_back(current->val);
                    current=current->right;
                }
            }
        } 
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        // InorderIter(root);
        morrisInorder(root);
        return ans;
    }
};


int main() {
    // Create a sample tree: 
    //       1
    //        \
    //         2
    //        /
    //       3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> result = sol.inorderTraversal(root);

    // Print the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}