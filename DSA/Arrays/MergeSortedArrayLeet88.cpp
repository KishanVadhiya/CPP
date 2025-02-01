// leetcode url - https://leetcode.com/problems/merge-sorted-array/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int gap=(m+n)/2 + (m+n)%2;

        while(gap>0){
            int start=0;
            int end=gap;

            while(end<m+n){
                int *left,*right;
                if(start<m){
                    left=&nums1[start];
                }else{
                    left=&nums2[start-m];
                }

                if(end<m){
                    right=&nums1[end];
                }else{
                    right=&nums2[end-m];
                }

                if(*left>*right){
                    swap(*left,*right);
                }
                start++;
                end++;


            }
            if(gap==1) break;
            gap=gap/2 + gap%2;

        }

        // for(auto it:nums1) cout<<it<<" ";
        // cout<<endl;
        // for(auto it:nums2) cout<<it<<" ";
        // cout<<endl;

        for(int i=0;i<n;i++){
            nums1[i+m]=nums2[i];
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    sol.merge(nums1, m, nums2, n);

    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}