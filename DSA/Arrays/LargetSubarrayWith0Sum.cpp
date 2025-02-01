// gfg url - https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1?category%5B%5D=Hash&company%5B%5D=Amazon&page=1&query=category%5B%5DHashcompany%5B%5DAmazonpage1company%5B%5DAmazoncategory%5B%5DHash&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=largest-subarray-with-0-sum
#include<iostream>
#include<vector>
#include<unordered_map>
// #include<algorithm>
using namespace std;
class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        int sum=0;
        unordered_map<int,int> umap;
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0) ans=i+1;
            else{
                if(umap.find(sum)!=umap.end()){
                    ans=max(ans,i-umap[sum]);
                }else{
                    umap[sum]=i;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, -2, 4, -4};
    cout << "Length of the longest subarray with 0 sum is " << sol.maxLen(arr) << endl;
    return 0;
}