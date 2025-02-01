// leetcode url - https://leetcode.com/problems/rotate-array/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        if(k==0) return;
        int start=0;
        int end=n-k-1;

        while(start<end){
            swap(nums[start++],nums[end--]);
        }
        start=n-k;
        end=n-1;

        while(start<end) swap(nums[start++],nums[end--]);

        start=0;
        end=n-1;

        while(start<end) swap(nums[start++],nums[end--]);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    
    cout << "Original array: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    sol.rotate(nums, k);
    
    cout << "Rotated array: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}