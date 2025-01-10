// leetcode url - https://leetcode.com/problems/binary-tree-right-side-view/
#include<iostream>
#include<queue>
#include<vector>
#include<map>
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
    vector<int> rightSideViewBFS(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr) return ans;
        queue<pair<int,TreeNode*>> q;
        map<int,int> m;
        q.push({0,root});

        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){

            TreeNode* node=q.front().second;
            int row=q.front().first;
            q.pop();

            if(node->left) q.push({row+1,node->left});
            if(node->right) q.push({row+1,node->right});

            m[row]=node->val;
            }

        }
            for(auto it:m){
                ans.push_back(it.second);
            }
            return ans;
    }

    void dfs(TreeNode* current,int lvl){
        if(current==nullptr) return ;

        if(ans.size()==lvl) ans.push_back(current->val);

        dfs(current->right,lvl+1);
        dfs(current->left,lvl+1);
    }

public:

    vector<int> rightSideView(TreeNode* root){
        // dfs(root,0);
        // return ans;
        return rightSideViewBFS(root);
    }
};

int main() {
    Solution sol;

    // Create a sample tree: 
    //       1
    //      / \
    //     2   3
    //      \   \
    //       5   4
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    vector<int> result = sol.rightSideView(root);

    cout << "Right side view of the binary tree is: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up the allocated memory
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}