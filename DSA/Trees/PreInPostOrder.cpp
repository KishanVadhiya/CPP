#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val){
        this->val=val;
    }
};

void AllTraversal(TreeNode* root,vector<int> &preorder,vector<int> &inorder,vector<int>& postorder){
    stack<pair<TreeNode*,int>> st;
    st.push({root,1});

    while(!st.empty()){
        cout << "Stack: ";
        stack<pair<TreeNode*, int>> temp = st;
        while (!temp.empty()) {
            cout << "(" << temp.top().first->val << ", " << temp.top().second << ") ";
            temp.pop();
        }
        cout << endl;
        // cout<<"Got segmentation fault"<<endl<<endl;
        int* num=&(st.top().second);
        TreeNode* current=st.top().first;

        if(*num==1){
            (*num)++;
            preorder.push_back(current->val);
            if(current->left)   st.push({current->left,1});
        }else if(*num==2){
            (*num)++;
            inorder.push_back(current->val);
            if(current->right)  st.push({current->right,1});
        }else{
            postorder.push_back(current->val);
            st.pop();
        }
    }
}


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> preorder, inorder, postorder;
    AllTraversal(root, preorder, inorder, postorder);

    cout << "Preorder: ";
    for(int val : preorder) cout << val << " ";
    cout << endl;

    cout << "Inorder: ";
    for(int val : inorder) cout << val << " ";
    cout << endl;

    cout << "Postorder: ";
    for(int val : postorder) cout << val << " ";
    cout << endl;
}