// leetcode url - https://leetcode.com/problems/sudoku-solver/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    vector<vector<int>> rowMatrix;
    vector<vector<int>> colMatrix;
    vector<vector<int>> gridMatrix;
    bool isPossibleRowColGrid(vector<vector<int>> &rowColGridMatrix,int rowColGrid,int num,int temp){
        // cout<<"Before error : "<<rowColGrid<<" "<<num<<endl;
        // cout<<"Temp : "<<temp<<endl;
        if(rowColGridMatrix[rowColGrid][num]==1) return false;
        return true;
    }
    int subGridIdx(int i,int j){
        int idx=0;
        if(i<3){
            idx+=0;    
        }else if(i<6){
            idx+=1*3;
        }else{
            idx+=2*3;
        }

        if(j<3) idx+=0;
        else if(j<6) idx+=1;
        else idx+=2;

        return idx;
    }
    int remaining;
    void recur(vector<vector<char>>& board,int i,int j){
        if(i==9) return ;
        else if(j==9) recur(board,i+1,0);
        // cout<<"i: "<<i<<"j: "<<j<<endl;
        else if(board[i][j]!='.') recur(board,i,j+1);
        else{
            for(int x=1;x<=9;x++){
                if(isPossibleRowColGrid(rowMatrix,i,x-1,1) && isPossibleRowColGrid(colMatrix,j,x-1,2) &&isPossibleRowColGrid(gridMatrix,subGridIdx(i,j),x-1,3)){
                    remaining--;
                    rowMatrix[i][x-1]=1;
                    colMatrix[j][x-1]=1;
                    gridMatrix[subGridIdx(i,j)][x-1]=1;
                    board[i][j]=('0'+x);
                    recur(board,i,j+1);
                    if(remaining==0) return ;
                    board[i][j]='.';
                    gridMatrix[subGridIdx(i,j)][x-1]=0;
                    colMatrix[j][x-1]=0;
                    rowMatrix[i][x-1]=0;
                    remaining++;
                }
            }
        }



    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> temp1(9,vector<int>(9));
        vector<vector<int>> temp2(9,vector<int>(9));
        vector<vector<int>> temp3(9,vector<int>(9));
        rowMatrix=temp1;
        colMatrix=temp2;
        gridMatrix=temp3;
        remaining=81;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                remaining--;
                rowMatrix[i][int(board[i][j]-'0')-1]=1;
                colMatrix[j][int(board[i][j]-'0')-1]=1;
                // cout<<"Before error : "<<subGridIdx(i,j)<<" "<<board[i][j]-1<<endl;
                gridMatrix[subGridIdx(i,j)][int(board[i][j]-'0')-1]=1;
            }
        }

        recur(board,0,0);
    }
};

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    Solution solver;
    solver.solveSudoku(board);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}