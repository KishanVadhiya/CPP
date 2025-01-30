// gfg url - https://www.geeksforgeeks.org/problems/subset-sums2234/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=subset-sums

#include<iostream>
#include<vector>
using namespace std;
class Solution {
    vector<int> ans;
    void recur(vector<int>& arr,int start,int &sum,int &n){
        ans.push_back(sum);
        for(int i=start;i<n;i++){
            sum+=arr[i];
            recur(arr,i+1, sum,n);
            sum-=arr[i];
        }
    }
  public:
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        int sum=0;
        int n=arr.size();
        recur(arr,0,sum,n);
        return ans;
        
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3};
    vector<int> result = sol.subsetSums(arr);
    
    cout << "Subset sums are: ";
    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;
    
    return 0;
}