// leetcode url- https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
#include<iostream>
#include<string>
#include<queue>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        if(root==nullptr) return "";
        string ans="";
        ans+=to_string(root->val)+",";
        // cout<<ans<<endl;
        while(!q.empty()){
            TreeNode* current=q.front();
            q.pop();
            // cout<<"Root value : "<<endl;
            // cout<<current->val<<endl;

            if(current->left){
                q.push(current->left);
                // cout<<"Left "<<current->left->val<<endl;
                ans+=to_string(current->left->val)+",";
            }else{
                ans+="$,";
            }

            if(current->right){
                q.push(current->right);
                ans+=to_string(current->right->val)+",";
            }else{
                ans+="$,";
            }
        }
        ans.pop_back();
        // cout<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // cout<<endl<<endl<<"Inside deserialize"<<endl<<endl;
        if(data.length()==0) return nullptr;
        data=","+data+",";
        // cout<<data<<endl;
        int n=data.length();
        vector<int> nodes;
        int start=-1;
        for(int i=0;i<n;i++){
            if(data[i]==','){
                if(start==-1) start=i;
                else{
                    // cout<<"Inside else with start: "<<start<<" and end: "<<i<<endl;
                    string str=data.substr(start+1,i-start-1);
                    if(str=="$"){
                        nodes.push_back(1e9);
                    }else{
                        // cout<<str<<endl;
                        nodes.push_back(stoi(str));
                    }
                    start=i;
                }
            }
        }

        // for(auto it:nodes){
        //     cout<<it<<" ";
        // }

        TreeNode* root=new TreeNode(nodes[0]);
        // cout<<root->val<<endl;
        bfs(root,nodes);
        
        return root;

    }
    void bfs(TreeNode* root,vector<int> nodes){
        queue<TreeNode*> q;
        int i=1;
        q.push(root);

        while(!q.empty()){
            TreeNode* current=q.front();
            q.pop();

            if(nodes[i]!=1e9){
                current->left=new TreeNode(nodes[i]);
                q.push(current->left);
            }
            i++;
            if(nodes[i]!=1e9){
                current->right=new TreeNode(nodes[i]);
                q.push(current->right);
            }
            i++;
        }

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main() {
    Codec ser, deser;
    // Creating a sample tree: 
    //     1
    //    / \
    //   2   3
    //      / \
    //     4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Serialize the tree
    string serializedTree = ser.serialize(root);
    cout << "Serialized Tree: " << serializedTree << endl;

    // Deserialize the tree
    TreeNode* deserializedTree = deser.deserialize(serializedTree);
    cout << "Deserialized Tree Root Value: " << deserializedTree->val << endl;

    // Function to print the tree in level order
    auto printTree = [](TreeNode* root) {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if (current) {
                cout << current->val << " ";
                q.push(current->left);
                q.push(current->right);
            } else {
                cout << "null ";
            }
        }
        cout << endl;
    };

    // Print the deserialized tree
    printTree(deserializedTree);

    return 0;
}