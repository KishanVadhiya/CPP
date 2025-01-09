#include<iostream>
using namespace std;

struct Node{
    int val;
    struct Node* left;
    struct Node* right;

    Node(int val){
        this->val=val;
    }

};

void inorderTraversal(Node* node) {
    if (node == nullptr) return;
    inorderTraversal(node->left);
    cout << node->val << " ";
    inorderTraversal(node->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Inorder traversal of binary tree is: ";
    inorderTraversal(root);

    return 0;
}