// leetcode url -  https://leetcode.com/problems/kth-missing-positive-number/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr[0]>k){
            return k;
        }
        int n=arr.size();
        int start=0,end=n-1;
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;

            if(arr[mid]-mid-1<k){
                ans=mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }

        return arr[ans]+(k-(arr[ans]-ans-1));
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    int result = sol.findKthPositive(arr, k);
    cout << "The " << k << "th missing positive number is: " << result << endl;
    return 0;
}