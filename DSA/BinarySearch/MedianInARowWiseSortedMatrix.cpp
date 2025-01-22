// gfg url - https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=median-in-a-row-wise-sorted-matrix
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    int lowerBound(vector<int>& arr,int num,int end){
        int start=0;
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(arr[mid]<num){
                ans=mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans+1;
    }
    bool isPossible(vector<vector<int>>& mat,int mid,int m,int n,int mn){
        int sum=0;
        for(int i=0;i<m;i++){
            sum+=lowerBound(mat[i],mid,n-1);
        }
        // cout<<"sum : "<<sum<<endl;
        return sum<=mn/2;
    }
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int m=mat.size();
        int n=mat[0].size();
        int start=0,end=2000;
        int ans=-1;
        // cout<<"isPossible for mid=5 : "<<isPossible(mat,5,m,n,m*n)<<endl;
        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(isPossible(mat,mid,m,n,m*n)){
                ans=mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    cout << "Median is: " << sol.median(mat) << endl;
    return 0;
}