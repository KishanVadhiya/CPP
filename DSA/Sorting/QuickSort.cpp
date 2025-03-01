
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
      // Function to sort an array using quick sort algorithm.
      void quickSort(vector<int>& arr, int low, int high) {
          // code here
          if(low>high) return ;
          int pivotIdx=partition(arr,low,high);
          quickSort(arr,low,pivotIdx-1);
          quickSort(arr,pivotIdx+1,high);
      }
  
    public:
      // Function that takes last element as pivot, places the pivot element at
      // its correct position in sorted array, and places all smaller elements
      // to left of pivot and all greater elements to right of pivot.
      int partition(vector<int>& arr, int low, int high) {
          // code here
          
          int pivot=arr[high];
          
          int st=low;
          
          for(int j=low;j<high;j++){
              if(arr[j]<pivot) swap(arr[st++],arr[j]);
          }
          
          swap(arr[st],arr[high]);
          
          return st;
      }
  };

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    Solution sol;
    sol.quickSort(arr, 0, n-1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}