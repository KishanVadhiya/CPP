// leetcode url - https://leetcode.com/problems/word-ladder-ii/

#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
    private:
        vector<vector<string>> ans;
        unordered_map<string,int> levels;
        unordered_set<char> letters;

        void dfs(string node,int lvl,string beginWord,vector<string> currSeq){
            int n=beginWord.length();
            if(node==beginWord){
                vector<string> temp=currSeq;
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
                return ;
            }
            for(int i=0;i<n;i++){
                char org=node[i];
                for(char c:letters){
                    node[i]=c;
                    if(c==org){
                        continue;
                    }
                    if(levels.find(node)!=levels.end() && levels[node]==lvl){
                        vector<string> temp = currSeq;
                        temp.push_back(node);
                        dfs(node,lvl-1,beginWord,temp);
                    }
                }
                node[i]=org;
            }
        }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(),wordList.end());
        queue<string> q;
        int len=beginWord.length();
        int lvl=0;
        int n=wordList.size();
        if(words.find(endWord)==words.end()){
            return ans;
        }
        words.erase(beginWord);

        q.push(beginWord);
        levels[beginWord]=lvl;

        while(!q.empty()){
            string node=q.front();
            if(node==endWord) break;
            q.pop();
            lvl=levels[node]+1;

            for(int i=0;i<len;i++){
                char org=node[i];

                for(char c='a';c<='z';c++){
                    node[i]=c;
                    if(node[i]==org){
                        letters.insert(c);
                        continue;
                    }
                    if(words.find(node)!=words.end()){
                        q.push(node);
                        letters.insert(c);
                        levels[node]=lvl;
                        words.erase(node);
                    }
                }
                node[i]=org;
            }
        }

        dfs(endWord,levels[endWord]-1,beginWord,{endWord});
        return ans;
    }
};

int main() {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    
    vector<vector<string>> ladders = sol.findLadders(beginWord, endWord, wordList);
    
    for (const auto& ladder : ladders) {
        for (const auto& word : ladder) {
            cout << word << " ";
        }
        cout << endl;
    }
    
    return 0;
}
