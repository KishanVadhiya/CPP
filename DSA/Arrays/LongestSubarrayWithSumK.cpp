// gfg url - https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-sub-array-with-sum-k
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int> umap;
        int n=arr.size();
        int ans=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==k) ans=max(ans,i+1);
            if(umap.find(sum)==umap.end()){
                umap[sum]=i;
            }
            if(umap.find(sum-k)!=umap.end()){
                ans=max(ans,i-umap[sum-k]);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k = 15;
    int result = sol.longestSubarray(arr, k);
    cout << "Length of the longest subarray with sum " << k << " is: " << result << endl;
    return 0;
}