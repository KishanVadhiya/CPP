// leetcode url  - https://leetcode.com/problems/count-square-submatrices-with-all-ones/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int countSquares(vector<vector<int>>& matrix) {
            int m=matrix.size();
            int n=matrix[0].size();
            for(int i=1;i<m;i++){
                for(int j=1;j<n;j++){
                    if(matrix[i][j]==1){
                        matrix[i][j]+=min(matrix[i-1][j-1],min(matrix[i-1][j],matrix[i][j-1]));
                    }
                }
            }
    
            int ans=0;
            for(auto it:matrix){
                for(auto i:it){
                    ans+=i;
                }
            }
    
            return ans;
        }
    };

    int main() {
        Solution sol;
        vector<vector<int>> matrix = {
            {1, 0, 1},
            {1, 1, 0},
            {1, 1, 0}
        };
        cout << "Number of square submatrices with all ones: " << sol.countSquares(matrix) << endl;
        return 0;
    }