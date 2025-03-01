
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
      // Please change the array in-place
      void insertionSort(vector<int>& arr) {
          // code here
          int n=arr.size();
          for(int i=0;i<n;i++){
              int temp=arr[i];
              int j=i;
              while(j>0 && temp<arr[j-1]){ // we can also do arr[j]>arr[j-1] as after swapping the smaller element will always be at idx j
                  arr[j]=arr[j-1];
                  j--;
              }
              arr[j]=temp;
          }
      }
  };


int main() {
    Solution sol;
    vector<int> arr = {12, 11, 13, 5, 6};
    sol.insertionSort(arr);
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}