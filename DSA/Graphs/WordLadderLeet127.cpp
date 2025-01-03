// leetcode url - https://leetcode.com/problems/word-ladder/

#include<iostream>
#include<queue>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> uset(wordList.begin(),wordList.end());
        int n=beginWord.length();
        if(uset.find(endWord)==uset.end()){
            return 0;
        }
        unordered_set<char> charSet;

        for(auto it:wordList){
            for(auto i:it){
                charSet.insert(i);
            }
        }
        uset.erase(beginWord);

        queue<pair<string,int>> q;

        q.push(make_pair(beginWord,1));

        while(!q.empty()){
            // cout<<"Infinity"<<endl;
            string word=q.front().first;
            int sequenceSize=q.front().second;
            q.pop();
            for(int i=0;i<n;i++){
                char orgChar=word[i];
                for(auto j: charSet){
                    word[i]=j;
                    if(word==endWord) return sequenceSize +1;

                    if(uset.find(word)!=uset.end()){
                        q.push(make_pair(word,sequenceSize+1));
                        uset.erase(word);
                    }
                }
                word[i]=orgChar;
            }
        }

        return 0;
    }
};


int main() {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    
    int result = sol.ladderLength(beginWord, endWord, wordList);
    cout << "Length of shortest transformation sequence: " << result << endl;
    
    return 0;
}