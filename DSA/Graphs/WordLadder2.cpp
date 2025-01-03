
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<vector<string>> q;
        vector<vector<string>> ans;
        q.push({beginWord});

        unordered_set<string> uset(wordList.begin(),wordList.end());

        if(uset.find(endWord)==uset.end()){
            return ans;
        }
        uset.erase(beginWord);
        int len=uset.size()+1;
        int strLen=endWord.length();
        vector<string> toBeDeleted;
        int lvl=1;
        while(!q.empty()){
            vector<string> temp=q.front();

            cout << "Queue: ";
            queue<vector<string>> tempQ = q;
            while (!tempQ.empty()) {
                vector<string> path = tempQ.front();
                tempQ.pop();
                for (const auto& word : path) {
                    cout << word << " ";
                }
                cout << "| ";
            }
            cout << endl;
            q.pop();
            int n=temp.size();
            if(n>len){
                cout<<"Reached in break statement"<<endl;
                break;
            }
            if(n>lvl){
                for(auto it: toBeDeleted){
                    uset.erase(it);
                }
                toBeDeleted.clear();
                lvl=n;
            }
            if(temp[n-1]==endWord){
                ans.push_back(temp);
            }
            string node=temp[n-1];
            cout<<"Node is : "<<node<<endl;
            for(int i=0;i<strLen;i++){
                char org= node[i];

                for(char c='a';c<='z';c++){
    
                    if(c==org){
                        continue;
                    }
                    node[i]=c;
                    if(uset.find(node)!=uset.end()){
                        cout<<"Found the word  : "<<node<<endl;
                        vector<string> temp2=temp;
                        temp2.push_back(node);
                        q.push(temp2);
                        toBeDeleted.push_back(node);
                    }
                }
                node[i]=org;
            }
            // cout<<"Deleting : ";
            // for(auto it:toBeDeleted){
            //     cout<<it<<" ";
            //     uset.erase(it);
            // }
            // cout<<endl;
        }
        return ans;
    }
};




int main() {
    Solution solution;
    string beginWord = "red";
    string endWord = "tax";
    vector<string> wordList = {"ted", "tex", "red", "tax", "tad", "den", "rex", "pee"};
    
    vector<vector<string>> ladders = solution.findLadders(beginWord, endWord, wordList);
    
    cout << "Ladders from " << beginWord << " to " << endWord << ":\n";
    for (const auto& ladder : ladders) {
        for (const auto& word : ladder) {
            cout << word << " ";
        }
        cout << endl;
    }
    
    return 0;
}