// gfg url - https://www.geeksforgeeks.org/problems/merge-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=merge-sort
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
      void mergeSort(vector<int>& arr, int l, int r) {
          // code here
          if(l>=r) return ;
          int mid=l+(r-l)/2;
          mergeSort(arr,l,mid);
          mergeSort(arr,mid+1,r);
          merge(arr,l,mid,r);
      }
      
      void merge(vector<int>& arr,int s,int mid,int e){
          vector<int> sortedArray;
          
          int i=s;
          int j=mid+1;
          
          while(i<=mid && j<=e){
              if(arr[i]<arr[j]){
                  sortedArray.push_back(arr[i++]);
              }else{
                  sortedArray.push_back(arr[j++]);
              }
          }
          
          while(i<=mid){
              sortedArray.push_back(arr[i++]);
          }
          
          while(j<=e) sortedArray.push_back(arr[j++]);
          
          i=s;
          for(auto it:sortedArray){
              arr[i++]=it;
          }
          
      }
  };


int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int arr_size = arr.size();
    
    Solution ob;
    ob.mergeSort(arr, 0, arr_size - 1);
    
    cout << "Sorted array is: \n";
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}