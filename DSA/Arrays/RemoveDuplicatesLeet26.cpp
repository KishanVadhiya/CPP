// leetcode url - https://leetcode.com/problems/remove-duplicates-from-sorted-array/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int current=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>nums[current]){
                current++;
                swap(nums[i],nums[current]);
            }
        }
        return current+1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int newLength = sol.removeDuplicates(nums);
    cout << "The new length is: " << newLength << endl;
    cout << "The modified array is: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}