
#include<iostream>
#include<functional>
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
void insert(TreeNode* current,int val){
    if(val>current->val){
        if(current->right==nullptr){
            current->right=new TreeNode(val);
            return ;
        }else{
            insert(current->right,val);
        }
    }else{
        if(current->left==nullptr){
            current->left=new TreeNode(val);
            return ;
        }else{
            insert(current->left,val);
        }
    }
}
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr) return new TreeNode(val);
        insert(root,val);
        return root;
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(4);
    sol.insertIntoBST(root, 2);
    sol.insertIntoBST(root, 7);
    sol.insertIntoBST(root, 1);
    sol.insertIntoBST(root, 3);
    sol.insertIntoBST(root, 5);

    // Function to print the BST (in-order traversal)
    function<void(TreeNode*)> printInOrder = [&](TreeNode* node) {
        if (node == nullptr) return;
        printInOrder(node->left);
        cout << node->val << " ";
        printInOrder(node->right);
    };

    printInOrder(root);
    cout << endl;

    return 0;
}