// leetcode url - https://leetcode.com/problems/accounts-merge/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include<algorithm>

using namespace std;
class Solution {
private:
    int ultimateParentIndex(int node,vector<int> &parent){
        if(node==parent[node]){
            return node;
        }
        return parent[node]=ultimateParentIndex(parent[node],parent);
    }
    void unionSet(int node1,int node2,vector<int> &parent){

        int ultimateParentNode1=ultimateParentIndex(node1,parent);
        int ultimateParentNode2=ultimateParentIndex(node2,parent);

            parent[ultimateParentNode2]=ultimateParentNode1;
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int> umap;
        vector<vector<string>> ans(n);
        vector<int> parents(n);
        for(int i=0;i<n;i++){
            parents[i]=i;
            ans[i].push_back(accounts[i][0]);
        }
        for(int i=0;i<n;i++){
            int parent=i;
            for(int j=1;j<accounts[i].size();j++){
                if(umap.find(accounts[i][j])!=umap.end()){
                    parent=umap[accounts[i][j]];
                    unionSet(parent,i,parents);
                }
                umap[accounts[i][j]]=parent;
            }
        }


        for(auto &it:umap){
            int row=ultimateParentIndex(it.second,parents);
            ans[row].push_back(it.first);
        }


        for(int i=n-1;i>=0;i--){
            if(i!=parents[i]){
                ans.erase(ans.begin()+i);
            }else{
                sort(ans[i].begin()+1,ans[i].end());
            }
        }
        
        return ans;
    }

};

int main() {
    Solution solution;
    vector<vector<string>> accounts = {
        {"Alex", "Alex5@m.co", "Alex4@m.co", "Alex0@m.co"},
        {"Ethan", "Ethan3@m.co", "Ethan3@m.co", "Ethan0@m.co"},
        {"Kevin", "Kevin4@m.co", "Kevin2@m.co", "Kevin2@m.co"},
        {"Gabe", "Gabe0@m.co", "Gabe3@m.co", "Gabe2@m.co"},
        {"Gabe", "Gabe3@m.co", "Gabe4@m.co", "Gabe2@m.co"}
    };
    
    vector<vector<string>> mergedAccounts = solution.accountsMerge(accounts);
    
    for (const auto& account : mergedAccounts) {
        for (const auto& email : account) {
            cout << email << " ";
        }
        cout << endl;
    }
    
    return 0;
}