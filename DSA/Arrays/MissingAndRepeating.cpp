// leetcode url - https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-missing-and-repeating
#include<iostream>
#include<vector>
using namespace std;
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        
        int n=arr.size();
        vector<int> visited(n+1);
        int repeated=arr[0];
        for(auto it:arr){
            if(visited[it]){
                repeated=it;
            }else{
            visited[it]=1;
            }
        }
        
        int i=1;
        while(i<=n && visited[i]==1) i++;
        
        return {repeated,i};
        
        
    }
};

int main() {
    Solution sol;
    vector<int> arr = {4, 3, 6, 2, 1, 1};
    vector<int> result = sol.findTwoElement(arr);
    cout << "Repeating element: " << result[0] << endl;
    cout << "Missing element: " << result[1] << endl;
    return 0;
}