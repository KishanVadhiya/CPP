// gfg url - https://www.geeksforgeeks.org/problems/selection-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=selection-sort
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
      // Function to perform selection sort on the given array.
      void selectionSort(vector<int> &arr) {
          // code here
          int minIdx;
          int n=arr.size();
          for(int i=0;i<n;i++){
              minIdx=i;
              for(int j=i+1;j<n;j++){
                  if(arr[minIdx]>arr[j]) minIdx=j;
              }
              swap(arr[minIdx],arr[i]);
          }
      }
  };

int main() {
    Solution sol;
    vector<int> arr = {64, 25, 12, 22, 11};
    sol.selectionSort(arr);
    cout << "Sorted array: \n";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}