// leetcode url - https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
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
int ans=-1;
public:
void dfs(TreeNode* root,int &k){
    if(root==nullptr || k<=0) return ;
    dfs(root->left,k);
    k--;
    if(k==0) ans=root->val;
    dfs(root->right,k);

}
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        return ans;
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    int k = 1;
    cout << "The " << k << "th smallest element is " << sol.kthSmallest(root, k) << endl;

    k = 2;
    cout << "The " << k << "th smallest element is " << sol.kthSmallest(root, k) << endl;

    k = 3;
    cout << "The " << k << "th smallest element is " << sol.kthSmallest(root, k) << endl;

    k = 4;
    cout << "The " << k << "th smallest element is " << sol.kthSmallest(root, k) << endl;

    // Clean up memory
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}