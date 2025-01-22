// leetcode url - https://leetcode.com/problems/search-a-2d-matrix-ii/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    bool bs(vector<int> &arr,int target){
        int n=arr.size();
        if(target<arr[0] || target>arr[n-1]) return false;
        int start=0;
        int end=n-1;

        while(start<=end){
            int mid=start+(end-start)/2;

            if(arr[mid]==target) return true;
            else if(target>arr[mid]) start=mid+1;
            else end=mid-1;
        }
        return false;
    }

    bool searchMatrixIter(vector<vector<int>>& matrix,int target){
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0,j=n-1;

        while(i<m && j>=0){
            if(matrix[i][j]==target) return true;
            else if(target<matrix[i][j]) j--;
            else i++;
        }
        return false;
    }
public:
    bool searchMatrixBS(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();

        for(int i=0;i<m;i++){
            if(bs(matrix[i],target)) return true;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix,int target){
        return searchMatrixIter(matrix,target);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target = 5;

    if(sol.searchMatrix(matrix, target)) {
        cout << "Target " << target << " found in the matrix." << endl;
    } else {
        cout << "Target " << target << " not found in the matrix." << endl;
    }

    return 0;
}