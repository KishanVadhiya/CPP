// leetcode url - https://leetcode.com/problems/balanced-binary-tree/description/
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool Balanced = true;
    int dfs(TreeNode *root)
    {
        if (!Balanced || root == nullptr)
            return 0;

        int h1 = dfs(root->left);
        int h2 = dfs(root->right);

        if (abs(h1 - h2) > 1)
        {
            Balanced = false;
        }
        return 1 + max(h1, h2);
    }
    bool isBalanced(TreeNode *root)
    {
        dfs(root);
        return Balanced;
    }
};


int main()
{
    Solution solution;

    // Create a balanced binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(3);

    // Check if the tree is balanced
    if (solution.isBalanced(root))
    {
        cout << "The tree is balanced." << endl;
    }
    else
    {
        cout << "The tree is not balanced." << endl;
    }

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}