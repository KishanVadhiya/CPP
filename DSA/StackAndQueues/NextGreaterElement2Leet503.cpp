// leetcode url - https://leetcode.com/problems/next-greater-element-ii/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int maxIdx=0;
        int n=nums.size();
        stack<int> st;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[maxIdx]) maxIdx=i;
        }
        int gap=maxIdx+1;

        for(int i=0;i<n;i++){
            int idx=(i+gap)%n;
            while(!st.empty() && nums[idx]>nums[st.top()]){
                nums[st.top()]=nums[idx];
                st.pop();
            }
            st.push(idx);
        }

        while(!st.empty()){
            nums[st.top()]=-1;
            st.pop();
        }

        return nums;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1};
    vector<int> result = sol.nextGreaterElements(nums);

    cout << "Next greater elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}