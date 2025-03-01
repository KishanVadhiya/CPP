// gfg url - https://www.geeksforgeeks.org/problems/bubble-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bubble-sort
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
      // Function to sort the array using bubble sort algorithm.
      void bubbleSort(vector<int>& arr) {
          // Your code here
          int flag=true;
          int n=arr.size();
          for(int i=0;i<n;i++){
              flag=true;
              for(int j=1;j<n;j++){
                  if(arr[j]<arr[j-1]){
                      swap(arr[j],arr[j-1]);
                      flag=false;
                  }
              }
              if(flag) break;
          }
      }
  };


int main() {
    Solution sol;
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    sol.bubbleSort(arr);
    cout << "Sorted array: \n";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}