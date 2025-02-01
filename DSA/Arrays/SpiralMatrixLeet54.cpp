// leetcode url - https://leetcode.com/problems/spiral-matrix/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int endR=matrix.size()-1;
        int endC=matrix[0].size()-1;
        int startR=0;
        int startC=0;

        while(true){
            // upper Row traversal
            for(int j=startC;j<=endC;j++){
                ans.push_back(matrix[startR][j]);
            }
            startR++;
            if(startR>endR) break;

            for(int i=startR;i<=endR;i++){
                ans.push_back(matrix[i][endC]);
            }
            endC--;
            if(endC<startC) break;

            for(int j=endC;j>=startC;j--){
                ans.push_back(matrix[endR][j]);
            }
            endR--;
            if(endR<startR) break;
            for(int i=endR;i>=startR;i--){
                ans.push_back(matrix[i][startC]);
            }
            startC++;
            if(startC>endC) break;
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = sol.spiralOrder(matrix);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}