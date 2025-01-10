// gfg url - https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=root-to-leaf-paths

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
vector<vector<int>> ans;
void dfs(TreeNode* root,vector<int> &path){
    path.push_back(root->val);
    if(root->left==nullptr && root->right==nullptr) ans.push_back(path);
    
    if(root->left) dfs(root->left,path);
    if(root->right) dfs(root->right,path);

    path.pop_back();
}
  public:
    vector<vector<int>> Paths(TreeNode* root) {
        // code here
        vector<int> path;
        dfs(root,path);
        return ans;
    }
};


int main() {
    Solution sol;
    
    // Creating a sample tree: 
    //         1
    //        / \
    //       2   3
    //      / \   \
    //     4   5   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    vector<vector<int>> paths = sol.Paths(root);
    
    // Printing the paths
    for (const auto& path : paths) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    // Freeing the allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;
    
    return 0;
}