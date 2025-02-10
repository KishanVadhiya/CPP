// gfg url - https://www.geeksforgeeks.org/problems/the-celebrity-problem/1
#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
      // Function to find if there is a celebrity in the party or not.
      int celebrity(vector<vector<int> >& mat) {
          // code here  
          int start=0;
          int n=mat.size();
          int end=n-1;
          
          while(start<end){
              if(mat[start][end]==1){
                  start++;
              }else{
                  end--;
              }
          }
          
          for(int i=0;i<n;i++){
              if(i==start) continue;
              if(mat[i][start]!=1 || mat[start][i]!=0) return -1;
          }
          
          return start;
      }
  };


int main() {
    Solution sol;
    vector<vector<int>> mat = {{0, 1, 0},
                               {0, 0, 0},
                               {0, 1, 0}};
    int result = sol.celebrity(mat);
    if (result == -1) {
        cout << "No celebrity found" << endl;
    } else {
        cout << "Celebrity is at index: " << result << endl;
    }
    return 0;
}