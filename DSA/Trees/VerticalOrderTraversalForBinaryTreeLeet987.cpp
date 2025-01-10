

#include<iostream>
#include<vector>
#include<map>
#include<set>
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
map<int,multiset<pair<int,int>>> mset;
void dfs(int col,int row,TreeNode* current){
    if(current==nullptr) return ;
    // sortedMap[col].insert(current->val);
    mset[col].insert({row,current->val});
    // mset.insert({col,{row,current->val}});

    dfs(col-1,row+1,current->left);
    dfs(col+1,row+1,current->right);
}
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(0,0,root);
        int i=0;
        // for(auto it:mset){
        //     cout<<it.first<<" -> ";
        //     for(auto j:it.second){
        //         cout<<"( "<<j.first<<", "<<j.second<<" )  ";
        //     }
        //     cout<<endl;
            
        // }
        for(auto it:mset){
            ans.push_back(vector<int>());
            // cout<<"Error at outer i: "<<i<<endl;
            for(auto j:it.second){
                // cout<<"Error at i : "<<i<<endl<<j.second;

                ans[i].push_back(j.second);
            }
            i++;
        }
        return ans;
    }
};



int main() {
    Solution sol;
    
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Call the verticalTraversal function
    vector<vector<int>> result = sol.verticalTraversal(root);

    // Print the result
    for (const auto& vec : result) {
        for (int val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Clean up the allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}