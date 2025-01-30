// leetcode url - https://leetcode.com/problems/n-queens/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
    vector<vector<string>> ans;
    bool isPossible(vector<int>& visitedRow,vector<int> &visitedLeftUpperDiagonal,vector<int> &visitedLeftLowerDiagonal,int i,int j,int n){
        if(visitedRow[i]==1) return false;
        int leftUpperDiagonal=n-1 + j-i;
        if(visitedLeftUpperDiagonal[leftUpperDiagonal]) return false;
        int leftLowerDiagonal= i+j;
        if(visitedLeftLowerDiagonal[leftLowerDiagonal]) return false;
        return true;
    }
    void backtrack(vector<string> &board,int currentCol,vector<int> &visitedRow,vector<int> &visitedDiagonal1,vector<int> &visitedDiagonal2,int n){
        // for(int x=0;x<n;x++){
        //             for(int y=0;y<n;y++){
        //                 cout<<board[x][y]<<" ";
        //             }
        //             cout<<endl;
        //         }
        if(currentCol==n){
            ans.push_back(board);
            return ;
        }
        for(int i=0;i<n;i++){
            // if(currentCol==0){
            //     cout<<"Current col is 0 "<<endl;
            //     for(int x=0;x<n;x++){
            //         for(int y=0;y<n;y++){
            //             cout<<board[x][y]<<" ";
            //         }
            //         cout<<endl;
            //     }
            // }
            if(isPossible(visitedRow,visitedDiagonal1,visitedDiagonal2,i,currentCol,n)){
                
                // cout<<"True for i: "<<i<<" j: "<<currentCol<<endl;
                visitedRow[i]=1;
                int diagonal1=n-1+currentCol-i;
                visitedDiagonal1[diagonal1]=true;
                int diagonal2=i+currentCol;
                visitedDiagonal2[diagonal2]=true;
                board[i][currentCol]='Q';
                backtrack(board,currentCol+1,visitedRow,visitedDiagonal1,visitedDiagonal2,n);
                // cout<<"Reached here after backtrack"<<endl;
                visitedDiagonal1[diagonal1]=0;
                visitedDiagonal2[diagonal2]=0;
                visitedRow[i]=0;
                board[i][currentCol]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board[i].push_back('.');
            }
        }
        vector<int> row(n);
        vector<int> temp1(2*(n)-1);
        vector<int> temp2(2*(n)-1);
        backtrack(board,0,row,temp1,temp2,n);
        return ans;
    }
};
int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    Solution sol;
    vector<vector<string>> result = sol.solveNQueens(n);
    for (const auto& solution : result) {
        for (const auto& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}