// leetcode url - https://leetcode.com/problems/rotate-image/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
    void rotate2(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int startR=0;
        int startC=0;
        int endR=n-1;
        int endC=n-1;

        while(startR<=endR){
            int NumEl=endR-startR;
            for(int i=0;i<NumEl;i++){
                int temp=matrix[startR][startC+i];
                matrix[startR][startC+i]=matrix[endR-i][startC];
                matrix[endR-i][startC]=matrix[endR][endC-i];
                matrix[endR][endC-i]=matrix[startR+i][endC];
                matrix[startR+i][endC]=temp;
            }

            startR++;
            endR--;
            startC++;
            endC--;
        }
    }
};


int main() {
    Solution sol;
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<vector<int>> matrix2 = matrix1; // Copy of matrix1 for the second rotate function

    cout << "Original matrix:" << endl;
    for (const auto& row : matrix1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    sol.rotate(matrix1);
    cout << "Matrix after rotate function:" << endl;
    for (const auto& row : matrix1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    sol.rotate2(matrix2);
    cout << "Matrix after rotate2 function:" << endl;
    for (const auto& row : matrix2) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}