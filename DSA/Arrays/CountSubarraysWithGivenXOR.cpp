// gfg url - https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int resxor=0;
        long ans=0;
        int n=arr.size();
        unordered_map<int,int> umap;
        for(int i=0;i<n;i++){
            resxor^=arr[i];
            if(resxor==k) ans++;
                int temp=resxor^k;
                if(umap.find(temp)!=umap.end()){
                    ans+=umap[temp];
                }
                umap[resxor]++;
                
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    cout << "Number of subarrays with given XOR is " << sol.subarrayXor(arr, k) << endl;
    return 0;
}