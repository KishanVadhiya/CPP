// gfg url - https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

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
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(TreeNode *root) {
        // code here
        map<int,int> m;
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                pair<int,TreeNode*> current=q.front();
                q.pop();
                int c=current.first;
                TreeNode* node=current.second;
                

                if(m.find(c)==m.end()){
                    m[c]=node->val;
                }
                
                if(node->left){
                    q.push({c-1,node->left});
                }
                if(node->right){
                    q.push({c+1,node->right});
                }
                
            }
        }
        
        vector<int> ans;
        for(auto it:m){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};


int main() {
    Solution solution;

    // Creating a sample binary tree:
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

    vector<int> result = solution.topView(root);

    cout << "Top view of the binary tree is: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up the allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}