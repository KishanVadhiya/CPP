// leetcode url -https://leetcode.com/problems/word-search/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    int delRow[4]={0,-1,0,1};
    int delCol[4]={1,0,-1,0};
    bool dfs(vector<vector<char>>& board,string &word,int currentIndex,int &n,int i,int j,int &r,int &c){
        if(n==currentIndex) return true;
        char temp=board[i][j];
        board[i][j]='0';
        bool ans=false;
        for(int x=0;x<4 && !ans;x++){
            int nRow=i+delRow[x];
            int nCol=j+delCol[x];

            if(nRow>=0 && nCol>=0 && nRow<r && nCol<c && board[nRow][nCol]==word[currentIndex]){
                ans =dfs(board,word,currentIndex+1,n,nRow,nCol,r,c);
            }
        }
        board[i][j]=temp;
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size();
        int c=board[0].size();
        int n=word.length();

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,word,1,n,i,j,r,c)) return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    if(sol.exist(board, word)) {
        cout << "Word found in the board" << endl;
    } else {
        cout << "Word not found in the board" << endl;
    }
    return 0;
}