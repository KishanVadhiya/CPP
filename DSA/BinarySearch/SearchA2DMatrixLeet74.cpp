// leetcode url - https://leetcode.com/problems/search-a-2d-matrix/submissions/1516536431/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrixIter(vector<vector<int>>& matrix, int target) {
        int i=0,j=0;
        int m=matrix.size();
        int n=matrix[0].size();

        while(true){
            // cout<<i<<" "<<j<<endl;
            // cout<<matrix[i][j]<<endl;
            // cout<<target<<endl;
            // cout<<(matrix[i][j]==target)<<endl;
            if(matrix[i][j]==target) return true;
            else if(i+1<m && matrix[i+1][j]<=target) i++;
            else if(j+1<n && matrix[i][j+1]<=target) j++;
            else return false;
        }
        return false;
    }

    bool searchMatrixBS(vector<vector<int>>& matrix, int target){
        int start=0;
        int end=matrix.size()-1;
        int targetRow=0;
        while(start<=end){
            int mid=start+(end-start)/2;

            if(matrix[mid][0]==target) return true;

            else if(matrix[mid][0]<target){
                start=mid+1;
                targetRow=mid;
            }else{
                end=mid-1;
            }
        }

        start=0;
        end=matrix[0].size()-1;

        while(start<=end){
            int mid=start+(end-start)/2;

            if(matrix[targetRow][mid] == target) return true;
            else if(matrix[targetRow][mid]<target) start=mid+1;
            else end=mid-1;
        }
        return false;
    }

    bool searchMatrixBS2(vector<vector<int>>& matrix, int target){
        int m=matrix.size();
        int n=matrix[0].size();
        int start=0;
        int end=m*n-1;

        while(start<=end){
            int mid=start+(end-start)/2;

            int i=mid/n;
            int j=mid%n;

            if(matrix[i][j]==target) return true;
            if(matrix[i][j]<target) start=mid+1;
            else end=mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        return searchMatrixBS2(matrix,target);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;

    if (sol.searchMatrix(matrix, target)) {
        cout << "Target " << target << " found in the matrix." << endl;
    } else {
        cout << "Target " << target << " not found in the matrix." << endl;
    }

    return 0;
}