// leetcode url - https://leetcode.com/problems/median-of-two-sorted-arrays/description/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int n1=nums1.size();
       int n2=nums2.size();
       if(n1>n2) return findMedianSortedArrays(nums2,nums1);
       if(n1==0){
            int temp=n2/2;
        if(n2%2==0){
            return (nums2[temp]+nums2[temp-1])/2.0;
        }else{
            return nums2[temp];
        }
       }
       if(n2==0){
        int temp=n1/2;
        if(n1%2==0){
            return (nums1[temp]+nums1[temp-1])/2.0;
        }else{
            return nums1[temp];
        }
       }
       int total=n1+n2;
       int idx=(total+1)/2;
       if(nums1[n1-1]<=nums2[0]){
        if(n1==n2)  return (nums1[n1-1]+nums2[0])/2.0;
            idx-=(n1);
        if((total)%2==1){
            return nums2[idx-1];
        }else{
            return (nums2[idx]+nums2[idx-1])/2.0;
        }
       }
       if(nums2[n2-1]<=nums1[0]){
        if(n1==n2) return (nums2[n1-1]+nums1[0])/2.0;
        if(total%2==1){
            return nums2[idx-1];
        }else{
            return (nums2[idx]+nums2[idx-1])/2.0;
        }
       }
       int start=0;
       int end=n1;
       while(start<=end){
        int mid=start+(end-start)/2;
        int l1=(mid==0)?INT_MIN:nums1[mid-1];
        int r1=(mid==n1)?INT_MAX:nums1[mid];
        int l2=nums2[idx-mid-1];
        int r2=(idx-mid<n2)?nums2[idx-mid]:INT_MAX;
        if(l1<=r2 && l2<=r1){
            if(total%2==0) return (max(l1,l2)+min(r1,r2))/2.0;
            else return max(l1,l2);
        }

        else if(l2>r1){
            start=mid+1;
        }else{
            end=mid-1;
        }

       }
       return 0; 
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Median of nums1 and nums2 is: " << sol.findMedianSortedArrays(nums1, nums2) << endl;

    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    cout << "Median of nums3 and nums4 is: " << sol.findMedianSortedArrays(nums3, nums4) << endl;

    vector<int> nums5 = {0, 0};
    vector<int> nums6 = {0, 0};
    cout << "Median of nums5 and nums6 is: " << sol.findMedianSortedArrays(nums5, nums6) << endl;

    vector<int> nums7 = {};
    vector<int> nums8 = {1};
    cout << "Median of nums7 and nums8 is: " << sol.findMedianSortedArrays(nums7, nums8) << endl;

    vector<int> nums9 = {2};
    vector<int> nums10 = {};
    cout << "Median of nums9 and nums10 is: " << sol.findMedianSortedArrays(nums9, nums10) << endl;

    return 0;
}