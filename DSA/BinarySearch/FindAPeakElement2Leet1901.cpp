// leetcode url - https://leetcode.com/problems/find-a-peak-element-ii/
#include<iostream>
#include<vector>
using namespace std; 
class Solution {
    int maxElement(vector<vector<int>>& arr,int col,int m){
        int ans=0;
        for(int i=0;i<m;i++){
            if(arr[i][col]>arr[ans][col]){
                ans=i;
            }
        }
        return ans;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        int start=0,end=n-1;

        while(start<=end){
            int mid=start+(end-start)/2;
            int idx=maxElement(mat,mid,m);
            int left=(mid-1>=0)?mat[idx][mid-1]:-1;
            int right=(mid+1<n)?mat[idx][mid+1]:-1;
            
            if(mat[idx][mid]>left && mat[idx][mid]>right) return vector<int>{idx,mid};
            else if(left>mat[idx][mid]){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return vector<int>{-1,-1};
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1, 4, 3, 2},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    vector<int> peak = sol.findPeakGrid(mat);
    cout << "Peak element found at: [" << peak[0] << ", " << peak[1] << "]" << endl;
    return 0;
}