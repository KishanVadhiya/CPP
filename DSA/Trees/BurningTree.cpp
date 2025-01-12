// gfg url - https://www.geeksforgeeks.org/problems/burning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=burning-tree

#include<iostream>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
    unordered_map<TreeNode*,TreeNode*> umap;
    TreeNode* t;
    void parentNode(TreeNode* current,int target){
        if(current->val==target) t=current;
        if(current->left){
            umap[current->left]=current;
            parentNode(current->left,target);
        }
        if(current->right){
            umap[current->right]=current;
            parentNode(current->right,target);
        }
    }
  public:
    int minTime(TreeNode* root, int target) {
        // code here
        parentNode(root,target);
        unordered_set<TreeNode*> burned;
        queue<TreeNode*> q;
        q.push(t);
        int time=0;
        while(!q.empty()){
            int n=q.size();
            time++;
            for(int i=0;i<n;i++){
                TreeNode* current=q.front();
                q.pop();
                burned.insert(current);
                
                if(current->left && burned.find(current->left)==burned.end()){
                    q.push(current->left);
                }
                if(current->right && burned.find(current->right)==burned.end()){
                    q.push(current->right);
                }
                if(umap.find(current)!=umap.end() && burned.find(umap[current])==burned.end()){
                    q.push(umap[current]);
                }
            }
        }
        return time-1;
    }
};


int main() {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);

    int target = 5;
    cout << "Minimum time to burn the tree: " << sol.minTime(root, target) << endl;

    return 0;
}